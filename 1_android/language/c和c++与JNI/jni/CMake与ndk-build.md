## ndk-build
运行 ndk-build 脚本相当于运行以下命令：
```
$GNUMAKE -f <ndk>/build/core/build-local.mk
<parameters>
```
`$GNUMAKE` 指向 GNU Make 3.81 或更高版本   
`<ndk>` 则指向 NDK 安装目录

命令 | 作用
--- | ---
`ndk-build clean` | 清除已生成的二进制文件
`ndk-build V=1` | 
`ndk-build -B` | 
`ndk-build -B V=1` | 执行完整重构，并显示完整构建命令
`ndk-build NDK_LOG=1` | 显示NDK内部日志
`ndk-build NDK DEBUG=1` | 开启Debug模式
`ndk-build NDK_DEBUG=0` | 关闭Debug模式
`ndk-build NDK_HOST_32BIT=1` | 始终使用的是32位工具链
`ndk-build NDK_APPLICATION_MK=<File>` | 使用指定的Application.mk
`ndk-build -C <project>` | 指定C Project路径

Android.mk
```
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := hello-jni
LOCAL_SRC_FILES := hello-jni.c
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := foo
LOCAL_SRC_FILES := foo/foo.c
LOCAL_EXPORT_CFLAGS := -DFOO=1
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := bar
LOCAL_SRC_FILES := bar.c
LOCAL_CFLAGS := -DBAR=2
LOCAL_STATIC_LIBRARIES := foo
include $(BUILD_SHARED_LIBRARY)
```
Application.mk
```
APP_ABI := armeabi-v7a arm64-v8a x86 x86_64 all
```
## CMake



https://developer.android.com/training/articles/perf-jni
https://developer.android.com/ndk/samples