#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_yigelangzi_myndk_MainActivity_stringFromJNI( // 命名格式：PackageName_ActivityName_MethodName
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
