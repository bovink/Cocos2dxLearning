//
// Created by 吴宗刚 on 2019/4/12.
//

#ifndef PROJ_ANDROID_JNIBRIDGE_H
#define PROJ_ANDROID_JNIBRIDGE_H

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;
using namespace std;

static void testSomething(int type);

void testSomething(int type) {

    if (type == 1) {

        __CCLOGWITHFUNCTION("%s,测试1", __FUNCTION__);
    } else if (type == 2) {

        __CCLOGWITHFUNCTION("%s,测试2", __FUNCTION__);
    }
    cout << "testSomething" << endl;
}

class JniBridge {

};


#endif //PROJ_ANDROID_JNIBRIDGE_H
