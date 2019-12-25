package com.jack.learning.ndk;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.jack.learning.ndk.cmake.JNICMake;
import com.jack.learning.ndk.cmakeTwo.JNICMakeTwo;
import com.jack.learning.ndk.mk.JNIMK;
import com.jack.learning.ndk.mkhandleimage.JNIMKHandleImage;
import com.jack.learning.ndk.mkhandleimage.ProcessResult;

public class MainActivity extends Activity {
    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //CMakeList.txt文件编译cpp文件
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(JNICMake.test());

        TextView tv1 = findViewById(R.id.sample_text1);
        tv1.setText(new JNICMakeTwo().test());

        //mk编译cpp文件 //测试完成
//        TextView learning_mk = findViewById(R.id.learning_mk);
//        learning_mk.setText("learning-mk:\n" + JNIMK.test() + " " + JNIMK.getStringFromJNI(39));
//
//        TextView learning_mk_handle_image = findViewById(R.id.learning_mk_handle_image);
//        learning_mk_handle_image.setText("learning-mk-handle-image:\n" + JNIMKHandleImage.test());
//        byte[] data = new byte[]{1, 2, 3, 4};
//        ProcessResult processResult = JNIMKHandleImage.processByteArray(data, 2, 2);
//        Log.d(TAG, "[processByteArray] ProcessResult:" + processResult);
    }


}
