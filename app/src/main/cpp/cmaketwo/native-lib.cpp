#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_jack_learning_ndk_cmakeTwo_JNICMakeTwo_test(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "call libjni-cmake-two.so success.";
    return env->NewStringUTF(hello.c_str());
}
