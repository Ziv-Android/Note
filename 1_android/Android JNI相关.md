## 架构选择
1. so文件兼容问题：v7库（32位）兼容v8库（64位），但兼容模式下一些库容易产生异常，如libc…
2. 兼容模式下armeabi下可加载armeabi-v7a（32位）库以提高部分性能，但不可加载armeabia-v8a（64位）库
3. 同一种类型的库（32位、64位）如果要提供，就提供一整套完整的文件
   
## so优化
1. 如果不是启动就需要的so，可交给CDN做动态下发加载
2. 隐藏符号表，只公开必要的：`-fvisibility=hidden`
3. 禁用C++ Exception和RTTI：`-fno-exceptions -fno-rtti`
4. 不要使用iostream，应优先使用Android Log
5. 使用gc-sections去除无用代码
```
LOCAL_CFLAGS += -ffunction-sections -fdata-sections
LOCAL_LDFLAGS += -Wl, --gc-srctions
```
6. 构建时使用splits进行分包
```
splits {
    abi {
        enable true
        reset()
        include "armeabi-v7a", "armeabi-v8a", "x86", "x86_64"
        universalApk ture
    }
}
```

## Native与Java方法如何绑定
静态：通过命名规则映射 -> extern "C" -> 规定符号表按C的方式 -> JNIEXPORT -> visibility("default")DEFAULT表中 -> JNICALL -> 函数调用惯例，规定函数调用栈如何入栈，如何清理等
动态：通过JNI函数注册

类别 | 动态绑定 | 静态绑定
--- | --- | ---
Native函数名 | 无 | 按照C的命名规则修饰函数名
Native函数可见性 | 无 | 必须可见
动态更换 | 可以 | 不可以
调用性能 | 无需查找 | 有额外的查找开销
开发体验 | 无副作用 | 重构代码较为复杂
AS支持 | 不能自动关联 | 自动关联跳转

## Native数据传递
### Bitmap数据
Bimap -> 由JNI层delegate方法，设置Native指针在Bitmap对象中，后续Native操作如copy，compress等方法，均通过该long数据作为指针操作bitmap对象

### 字符串数据
GetStringUTFChars/ReleaseStringUTFChars
const char* , Modified-UTF-8字节流, \0编码为0xC080, 不影响C字符串结尾

GetStringChars/ReleaseStringChars
const jchar* , JNI函数自动处理字节序转换, Java大端, C小端

GetStringUTFRegion/GetStringRegion
字符串拷贝, 先在C层创建足够容量的空间, 将字符串的某一部分复制到开辟好的空间, 针对性复制, **少量读取/修改时效率较高**

GetStringCrtical/ReleaseStringCritical
取原地址，Get后会锁定虚拟机GC操作，且不能有其他JNI操作，尽快Release释放

### localRef
有数量限制（大约512个左右），使用完需要主动释放
jobject obj = env -> GetObjectArrayElement(objArray, i)
jdouble lat = env ->
env -> DeleteLocalRef(obj)

### DirectBuffer
```java
ByteBuffer buffer = ByteBuffer.allocateDirect(100);
buffer.putInt(12306);
buffer.flip();
NativeCIntf.useDirectBuffer(buffer, buffer.limit())
```
```c
int * bufPtr = (int*) env -> GetDirectBufferAddress(buf);
for(int i = 0; i < legth / sizeof(int); i++) {
    LOGI("useArray: %d", bufPtr[i]);
}
```
减少字符串读取拷贝问题，但需要注意大小端字节序

## 全局捕获Native异常
SIGQUIT
SIGILL | 4 | 非法指令 | 损坏的可执行文件或者代码区损坏
SIGABRT | 6 | 进程发现错误或主动调用abort() | 例如，strlen()函数内部发现异常时会主动调用abort()函数
SIGBUS |10，7 | 不存在的物理地址，硬件错误 | 由硬件或系统引起
SIGFPE | 8 | 浮点运算错误 | 除0，余0，整数溢出
SIGSEGV | 11 | 段地址错误 | 空指针，访问不存在的地址空间，访问内核区，写只读空间，栈溢出，数组越界，野指针等
SIGPIPE | 13 | 管道错误，王没有reader的管道中写 | Linux中的socket，如果断了继续写。Signal(SIGPIPE, SIG_IGN)
SIGTERM

```c
static struct sigaction old_signalhandlers[NSIG];
void setUpGlobalSignalHandler() {
    struct sigaction handler;
    memset(&handler, sizeof(struct sigaction));
    handler.sa_sigaction = android_signal_handler;
    handler.sa_flags = SA_RESETHAND;

#define CACHSIG(X) sigcation(X, &handler, &old_signalhandlers[X])
    CATCHSIG(SIGQUIT);
    CATCHSIG(SIGILL);
    CATCHSIG(SIGABRT);
    CATCHSIG(SIGBUS);
    CATCHSIG(SIGFPE);
    CATCHSIG(SIGSEGV);
    CATCHSIG(SIGPIPE);
    CATCHSIG(SIGTERM);
#undef CACHSIG
}

static void android_signal_handler(int signum, siginfo_t *info, void *reserved) {
    if (javaVM) {
        JNIEnvHelper jniEnvHelper;
        jclass errorHandleClass = findClass(jniEnvHelper.env, "com/xxx/xx/native/HandleNativeError");
        if (errorHandleClass == NULL) {
            LOGE("Cannot get error handler class.");
        } else {
            jmathodID errorHandleMethod = jniEnvHelper.env -> GetStaticMethodID(errorHandleClass, "nativeErrorCallback", "(I)V");
            if (errorHandleMethod == NULL) {
                LOGE("Cannot get error handler method.");
            } else {
                LOGE("Call java back to notify a native crash.");
                jniEnvHelper.env -> CallStaticVoidMethod(errorHandleClass, errorHandleMethod, signum);
            }
        }
    } else {
        LOGE("Jni unload");
    }
    old_signalhandlers[signum].sa_handler(signum);
}

class JNIEnvHelper {
public:
    JNIEnv *env;
    JNIEnvHelper() {
        needDetach = false;
        if(javaVM -> GetEnv((void**)&env, JNI_VERSION) != JNI_OK) {
            if(javaVM -> AttachCurrentThread(&env, NULL) == JNI_OK) {
                needDetach = true;
            }
        }
    }
    ~JNIEnvHelper() {
        if (needDetach) {
            javaVM -> DetachCurrentThread();
        }
    }
private:
    bool needDetach;
}

// classloader不一定能找得到，且env的findclass返回的classloader也不一定是加载当前native线程的classloader，因此需要类似反射调用获取
jclass findClass(JNIEnv *env, const char* name) {
    if (env == NULL) return null;
    jclass classLoaderClass = env -> GetObjectClass(classLoader);
    jmathodID loadClassMethod = env -> GetMethodID(classLoaderClass, "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;");
    jclass cls = static_cast<jclass>(env -> CallObjectMethod(classLoader, loadClassMethod, env -> NewStringUTF(name)));
    return cls;
}

// JNI拿到的引用均为本地引用，出了函数就会被回收，如果需要保存需要声明成全局NewGlobalRef
static jobject classLoader;
jint setUpClassLoader(JNIEnv *env) {
    jclass applicationClass = env -> FindClass("com/xxx/xxx/xx/xxx");
    jclass classClass = env -> GetObjectClass(applicationClass);
    jmethodID getClassLoaderMethod = env -> GetMethodID(classClass, "getClassLoader", "()Ljava/lang/ClassLoader;");
    classLoader = env -> NewGlobalRef(rev -> CallObjetMethod(applicationClass, getClassLoaderMethod));
    return classLoader == NULL ? JNI_ERR : JNI_OK;
}

public class HandleNativeError {
    public static void nativeErrorCallback(int signal) {
        Log.e("NativeError", "[" + Thread.currentThread().getName() + "] Signal " + signal);
    }
}
```
javaVM为JNI_OnLoad时拿到的vm指针，全局不会发生变化，可保存以便后续逻辑使用

### 捕获Native异常后的堆栈信息
1. 设置备用栈，防止SIGSEGV因栈溢出而出现堆栈被破坏, sigaltstack函数允许进程创建一个备用的栈，供信号处理函数使用
2. 创建独立线程在那个们用于堆栈收集并回调至Java层
3. 收集堆栈信息[4.1.1, 5.0)libcorkscrew.so，5.0及以后使用自己编译的libunwind.so，也可以使用系统函数_Unwind_Backtrace函数
4. 通过线程关联Native异常对应的Java堆栈（使用线程名去做一一对应）

### 编译so库的其他语言
Golang
Rust
KotlinNative
ScalaNative

#### Golang
https://juejin.cn/post/6861129639440580622#heading-0
https://ejin66.github.io/2018/09/15/go-to-so-android.html
1. 安装配置Go环境
简单来说 有几个环境变量要设置一下
```
GOARCH=CPU 类型
GOOS=设备类型
CGO_ENABLED=1
CC=ndk 里的 clang,需要是对应 CPU 版本的, API 呢建议是最低
```
这里单独说明一下, 高版本的 ndk 用的是 clang, 低版本用的是 gcc, 这个根据你情况来, 个人建议直接用 21.0.6113669版本, 这个我测试过, 没有问题, ndk20 我也试过, 也是 ok 的

go build 命令，-buildmode=c-shared 构建类型, 使用 go help buildmode查看, 安卓一般用c-shared就可以了, 意思就是 c 类型的共享库(动态库)，-o 后面跟输出的位置, 一般建议使用 libxxx.so 的格式, 相对的, 头文件也会被生成在同一目录下, xxx 就是库的名字, 对应到 Java 里加载库的方法就是System.loadLibrary("xxx") 而不是System.loadLibrary("libxxx")，最后一个是需要编译的 go 文件了

CPU 类型和设备类型可以使用go tool dist list查看
2. package一定要是main(强制规定)，一定要包含main函数(强制规定)，import "C", 不能少, 因为要编译出 c(c++)的头文件，每个方法前要加//export 方法名, 这里要注意// 和 export间不能有空格，方法名和 go 的方法名必须完全一样，方法名不能是 c 内置的方法名, 比如remove就不行

3. 执行
```shell
export ANDROID_NDK_HOME=$ANDROID_HOME/ndk/21.0.6113669

export GOARCH=arm
export GOOS=android
export CGO_ENABLED=1
# export CGO_LDFLAGS=--sysroot=%NDK_ROOT%/platforms/android-21/arch-arm
# export CC=arm-linux-androideabi-gcc --sysroot=%NDK_ROOT%\platforms\android-21\arch-arm
export CC=$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/darwin-x86_64/bin/armv7a-linux-androideabi21-clang
go build -buildmode=c-shared -o output/android/armeabi-v7a/libadd.so add_library.go

echo "Build armeabi-v7a success"

export GOARCH=arm64
export GOOS=android
export CGO_ENABLED=1
# export CGO_LDFLAGS=--sysroot=%NDK_ROOT%/platforms/android-21/arch-arm
# export CC=arm-linux-androideabi-gcc --sysroot=%NDK_ROOT%\platforms\android-21\arch-arm
export CC=$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/darwin-x86_64/bin/aarch64-linux-android21-clang
go build -buildmode=c-shared -o output/android/arm64-v8a/libadd.so add_library.go

echo "Build arm64-v8a success"
```

常见问题
提示 -buildmode=c-shared not supported on windows/amd64 -buildmode=c-shared 对go 版本有要求，go version >= 1.10
提示 can't load package: package .: build constraints exclude all Go files in 需要先设置go env: set CGO_ENABLED=1
提示 unimplemented: 64-bit mode not compiled in 不支持64位的编译，修改GOARCH： set GOARCH=386

#### Kotlin native
```gradle
kotlin {
    targets {
        fromPreset(presets.androidNativeArm32, "HelloWorld")
        configure([HelloWorld]) {
            compliations.main.outputKinds "DYNAMIC"
        }
    }
    sourceSets {
        HelloWorldMain {

        }
        HelloWorldTest {

        }
    }
}
```
```java
public class HelloJNi extends AppCompatActivity {
    public native String stringFromJNI();
    public native void sayHello();
    public native void sayHello2();
    public native String callJava();
    public String callFromNative() {
        return "This is from Java!!!"
    }
}
```
静态注册
```
@CName("Java_com_example_hellojni_HelloJni_stringFromJNI")
fun stringFromJNI(env: CPointer<JNIEnvVar>, thiz: jobject): jstring {
    memScoped {
        return env.pointed.pointed!!.NewStringUTF!!.invoke(env, "This is from Kotlin Native!!".cstr.ptr)!!
    }
}

@CName("Java_com_example_hellojni_HelloJni_sayHello")
fun sayHello() {
    __android_log_print(ANDROID_LOG_INFO.toInt(), "Kn", "Hello %s", "Native")
}

@CName("Java_com_example_hellojni_HelloJni_callJava")
fun stringFromJNI(env: CPointer<JNIEnvVar>, thiz: jobject): jstring {
    memScoped {
        val jniEnvVal = env.pointed.pointed!!
        val jclass = jniEnvVal.GetObjectClass!!.invoke(env, thiz)
        val mathodId = jniEnvVal.GetMathodID!!.invoke(env, jclass, "callFromNative".cstr.ptr, "()Ljava/lang/String;".cstr.ptr)
        return jniEnvVal.CallObjectMethodA!!.invoke(env, thiz, methodId, null) as jstring
    }
}
```
动态注册
```
@CName("JNI_OnLoad")
fun JNI_OnLoad(vm: CPointer<JavaVMVar>, preserved: COpaquePointer):jint {
    return memScoped {
        val envStorage = alloc<CPointerVar<JNIEnvVar>>()
        val vmValue = vm.pointed.pointed!!
        val reslt = vmValue.GetEnv!!(vm, envStorage.ptr.reinterpret(), JNI_VERSION_1_6)
        if (result == JNI_OK) {
            val env = envStorage.pointed!!.pointed!!
            val jclass = env.FindClass!!(envStorage.value, "com/example/hellojni/HelloJni".cstr.ptr)
            val jniMethod = allocArray<JNINativeMethod>(1)
            jniMethod[0].fnPtr = staticCFunction(::sayHello2)
            jniMethod[0].name = "sayHello".cstr.ptr
            jniMethod[0].signature = "()V".cstr.ptr
            env.RegisterNatives!!(envStorage.value, jclass, jniMethod, 1)
        }
        JNI_VERSION_1_6
    }
}
```

https://blog.csdn.net/afei__/article/details/81290711
https://blog.csdn.net/sailuoatm/article/details/118463339
