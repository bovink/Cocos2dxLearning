//
// Created by 吴宗刚 on 2018/9/19.
//

#ifndef PROJ_ANDROID_CALLNATIVEINTERFACE_H
#define PROJ_ANDROID_CALLNATIVEINTERFACE_H


class CallNativeInterface {

public:

    CallNativeInterface();

    void printInfoFromNative();

    void showToast();

private:

    void* object;
};


#endif //PROJ_ANDROID_CALLNATIVEINTERFACE_H
