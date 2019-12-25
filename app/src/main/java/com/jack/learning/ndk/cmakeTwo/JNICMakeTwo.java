package com.jack.learning.ndk.cmakeTwo;

/*
 * author: Jack
 * created time:2019/12/15 20:16
 * description: 学习Cmake
 */
public class JNICMakeTwo {
    static {
        System.loadLibrary("jni-cmake-two");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String test();
}
