#include "com_jack_learning_ndk_mk_JNIMK.h"
#include "../util/Log.h"
#include "Parent.h"
#include "cstdio"

extern "C"
JNIEXPORT jstring JNICALL Java_com_jack_learning_ndk_mk_JNIMK_test
        (JNIEnv *env, jclass classz) {
    LOGI("Java_com_jack_learning_ndk_mk_JNIMK_test() 被调用");
    return env->NewStringUTF("call libjni-mk.so success.");
}

extern "C"
JNIEXPORT jstring JNICALL Java_com_jack_learning_ndk_mk_JNIMK_getStringFromJNI
        (JNIEnv *env, jclass clazz, jint ji) {
    LOGI("Java_com_jack_learning_ndk_mk_JNIMK_getStringFromJNI() 被调用");

    //在堆中新建对象
    Parent * parent = new Parent();
    int age = parent->getAge();
    LOGI("parent.age=%d", age);

    //在栈中新建对象
    Parent parent1;
    parent1.setAge(ji);
    LOGI("parent1.age=%d", parent1.getAge());

    //返回传入的参数
    char str[100];
    char str2[20] = "param is:";
    int a = ji;
    sprintf(str, "%s%d", str2, a);

    return env->NewStringUTF(str);
}