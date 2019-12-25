/*
 * author: Jack
 * created time:2019/12/15 21:57
 * description:
 */
#include "AlgFunc.h"
#include <cstdio>
#include <cstdlib>
#include "../util/Log.h"

char* imgToGrayARGB( char* buf, int w, int h) {
    LOGI("[imgToGrayARGB] byte==");
    char *cbuf;
    cbuf = buf; // 获取数组元素

    int alpha = 0xFF; // 不透明值
    unsigned int i, color;
    unsigned int red, green, blue;
    for (i = 0; i < h*w*4; i+=4) {
        red = (unsigned char)cbuf[i+0]; // 获得red值
        green = (unsigned char)cbuf[i+1]; // 获得green值
        blue = (unsigned char)cbuf[i+2]; // 获得blue值

        //查看几个颜色值
        if(i<10){
            LOGI("argb[%d]=(%d,%d,%d,%d)",i,cbuf[i+3],red,green,blue);
        }
        color = (red * 38 + green * 75 + blue * 15) >> 7; // 灰度算法（16位运算下7位精度）
//            color = (red * 299 + green * 587 + blue * 114 + 500) / 1000; // 灰度算法（缩放1000倍来实现整数运算算法）效果相同

        red = green = blue = color; // 以灰度值来设置rgb

        cbuf[i+3]=alpha;
        cbuf[i+2]=blue;
        cbuf[i+1]=green;
        cbuf[i+0]=red;
    }
    LOGI("==imgToGray byte complete==");
    return buf;
}
