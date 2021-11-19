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