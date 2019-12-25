/*
 * author: Jack
 * created time:2019/12/15 21:57
 * description:
 */
#ifndef LEARNING_NDK_ALGFUNC_H
#define LEARNING_NDK_ALGFUNC_H

typedef struct _Process_result {
    char strResult[32];
    int x;
    int y;
    int width;
    int height;
} Process_result;

char *imgToGrayARGB(char *buf, int w, int h);

#endif //LEARNING_NDK_ALGFUNC_H
