package com.jack.learning.ndk.cmake;

/*
 * author: Jack
 * created time:2019/12/15 20:16
 * description: 学习Cmake
 */
public class JNICMake {
    static {
        System.loadLibrary("jni-cmake");
    }

    public native static String test();
}
