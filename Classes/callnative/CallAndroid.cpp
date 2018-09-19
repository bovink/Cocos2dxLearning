//
// Created by 吴宗刚 on 2018/9/19.
//

#include "CallNativeInterface.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include "cocos2d.h"

USING_NS_CC;

CallNativeInterface::CallNativeInterface() {

}

void CallNativeInterface::printInfoFromNative(string &s) {
    JniHelper::callStaticVoidMethod("org/cocos2dx/cpp/AppActivity",
                                    "printInfo", s);
}

void CallNativeInterface::showToast() {
    JniHelper::callStaticVoidMethod("org/cocos2dx/cpp/AppActivity",
                                    "showToast");
}

#endif
