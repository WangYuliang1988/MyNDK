Android NDK 学习工程，参考：<https://blog.mindorks.com/getting-started-with-android-ndk-android-tutorial>

## NDK 简介
**NDK**（Native Development Kit）是Android推出的一套开发工具，允许在Android应用中运行C或C++代码
**JNI**（Java Native Interface）是Java推出的一个框架，允许JVM上运行的Java代码同C或C++代码之间相互调用
NDK中Java代码同C或C++代码之间的相互调用正是通过JNI实现的。

## 工程搭建（基于Android Studio 3.6）
1. 通过Android Studio的SDK Manager安装LLDB、NDK、CMake三个工具
2. 打开Android Studio，新建工程，选择Native C++工程模板，点击下一步
3. 输入工程名、包名、工程目录等信息，开发语言选kotlin，点击下一步
4. 选择用来编译C++代码的编译器，使用默认即可，点击完成

## 工程目录（基于Android Studio 3.6）
Android NDK工程目录与一般Android工程目录相比有以下不同：
1. app目录下增加了一个.cxx目录，用来记录NDK产生的一些运行信息
2. app/src/main目录下增加了一个cpp目录，该目录下包含C++代码文件以及用来将代码打包成so文件的CMakeList.txt文件

## 工程运行
1. 运行工程，App正常启动，Activity正常显示，成功

## 支持64位架构
1. 查看当前是否支持64位架构，通过Build->Build Bundle(s)/APK(s)->Build APK(s)生成APK文件，然后将APK文件拖到Android Studio，查看其目录结构，若lib目录下只有armeabi-v7a或者x86目录下有so文件，则说明还未支持64位架构
2. **armeabi-v7a**和**arm64-v8a**分别是对应ARM架构的32位和64位库文件夹
3. **x86**和**x86_64**分别是对应x86架构的32位和64位库文件夹
4. 打开app/build.gradle文件，在defaultConfig下增加：ndk.abiFilters 'armeabi-v7a','arm64-v8a','x86','x86_64'
5. 重新编译工程，App正常启动，通过Build->Build Bundle(s)/APK(s)->Build APK(s)生成APK文件，然后将APK文件拖到Android Studio，lib目录下x86、x86_64、arm64-v8a、armeabi-v7a四个文件夹下均生成了so文件，成功

## 问题记录
1. NDK not configured，右键工程->Open Module Settings->SDK Location，设置Android NDK Location