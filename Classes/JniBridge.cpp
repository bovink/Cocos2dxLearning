//
// Created by 吴宗刚 on 2019/4/12.
//

#include "JniBridge.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
extern "C" {

void Java_org_cocos2dx_cpp_AppActivity_testSomething(JNIEnv *, jobject *obj, jint type) {

    testSomething(type);
}
};
#endif
