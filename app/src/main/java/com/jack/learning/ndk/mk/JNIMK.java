package com.jack.learning.ndk.mk;

/*
 * author: Jack
 * created time:2019/12/15 21:57
 * description:
 */
public class JNIMK {
    static {
        //生成的so库名字为libjni-mk.so
        System.loadLibrary("jni-mk");
    }

    /**
     * 测试so库是否调用成功
     *
     * @return 测试字符串
     */
    public static native String test();

    /**
     * 从jni获取一个字符串
     * @param count
     * @return
     */
    public static native String getStringFromJNI(int count);

}
