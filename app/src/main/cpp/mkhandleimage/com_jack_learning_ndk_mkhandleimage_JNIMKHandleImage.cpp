//
// Created by Administrator on 2017/5/24.
//
#include "com_jack_learning_ndk_mkhandleimage_JNIMKHandleImage.h"
#include "../util/Log.h"

#include "AlgFunc.h"
#include <cstdlib>
#include <cstdio>
#include "cstring"

//#include<android/bitmap.h>

extern "C" JNIEXPORT jstring
JNICALL Java_com_jack_learning_ndk_mkhandleimage_JNIMKHandleImage_test
        (JNIEnv *env, jclass classz) {
    LOGI("Java_com_jack_learning_ndk_mkhandleimage_JNIMKHandleImage_test() 被调用");
    return env->NewStringUTF("call libjni-mkhandleImage.so success.");
}

extern "C" JNIEXPORT jstring
JNICALL Java_com_jack_learning_ndk_mkhandleimage_JNIMKHandleImage_readBitmap
        (JNIEnv *env, jclass clazz, jobject bitmap) {
    LOGI("Java_com_jack_learning_ndk_mkhandleimage_JNIMKHandleImage_readBitmap() 被调用");
    return env->NewStringUTF("读取图片成功");
}

extern "C" JNIEXPORT jobject
JNICALL Java_com_jack_learning_ndk_mkhandleimage_JNIMKHandleImage_processByteArray
        (JNIEnv *env, jclass obj, jbyteArray data, jint w, jint h) {
    //TODO 实现逻辑还有点问题
    LOGI("Java_com_jack_learning_ndk_mkhandleimage_JNIMKHandleImage_processByteArray() 被调用");
    LOGI("w=%d,h=%d", w, h);
    // 1.获取到 arr的大小
    int len = env->GetArrayLength(data);

    //2.取出数组中第一个元素的内存地址
    char *buf_pic = (char *) env->GetByteArrayElements(data, 0); // 获取int数组元素

    //转灰度图像
    imgToGrayARGB(buf_pic, w, h);
    LOGI("%s:after imgToGrayRGB", __func__);

    //定义结构体，赋值
    Process_result process_result;
    process_result.width = w;
    process_result.height = h;
    process_result.x = 0;
    process_result.y = 0;

    //获取Java中的实例类
    jclass jcInfo = env->FindClass("com/jack/learning/ndk/mkhandleimage/ProcessResult");

    //获取类中每一个变量的定义
    //int x
    jfieldID jfx = env->GetFieldID(jcInfo, "x", "I");
    //int y
    jfieldID jfy = env->GetFieldID(jcInfo, "y", "I");
    //int width
    jfieldID jfwidth = env->GetFieldID(jcInfo, "width", "I");
    //int height
    jfieldID jfheight = env->GetFieldID(jcInfo, "height", "I");
    //byte[] strResult
    jfieldID jfstrResult = env->GetFieldID(jcInfo, "strResult", "[B");//"Ljava/lang/String;"

    //创建新的对象
    jobject joInfo = env->AllocObject(jcInfo);

    //给类成员赋值
    env->SetIntField(joInfo, jfx, process_result.x);
    env->SetIntField(joInfo, jfy, process_result.y);
    env->SetIntField(joInfo, jfwidth, process_result.width);
    env->SetIntField(joInfo, jfheight, process_result.height);

    //数组赋值
    int nTmpLen = std::strlen(process_result.strResult);
    LOGI("log: strlen(process_result.strResult)=%d", nTmpLen);

    jbyteArray jarr = env->NewByteArray(nTmpLen);
    env->SetByteArrayRegion(jarr, 0, nTmpLen, (jbyte *) process_result.strResult);
    env->SetObjectField(joInfo, jfstrResult, jarr);
    return joInfo;
}