//
// Created by 吴宗刚 on 2019/4/12.
//

#ifndef PROJ_ANDROID_JNIBRIDGE_H
#define PROJ_ANDROID_JNIBRIDGE_H

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;
using namespace std;

static void testSomething();

void testSomething() {

    cout << "testSomething" << endl;
    __CCLOGWITHFUNCTION("%s", __FUNCTION__);
}

class JniBridge {

};


#endif //PROJ_ANDROID_JNIBRIDGE_H
