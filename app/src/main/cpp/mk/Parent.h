//
// Created by Administrator on 2017/5/24.
//

#ifndef NDKBASE_PARENT_H
#define NDKBASE_PARENT_H

class Parent
{
public:
    Parent();
    void setAge(int age);
    int getAge();

private:
    int mAge = 0;//默认我为0
};

#endif //NDKBASE_PARENT_H
