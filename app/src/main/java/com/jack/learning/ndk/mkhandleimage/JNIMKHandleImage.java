package com.jack.learning.ndk.mkhandleimage;

/*
 * author: Jack
 * created time:2019/12/15 22:36
 * description:
 */
public class JNIMKHandleImage {
    static {
        System.loadLibrary("jni-mkhandleImage");
    }

    /**
     * 测试so库是否调用成功
     *
     * @return 测试字符串
     */
    public static native String test();

    public static native String readBitmap(Object bitmap);

    public static native ProcessResult processByteArray(byte[] data, int w, int h);
}
