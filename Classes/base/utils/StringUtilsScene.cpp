//
// Created by 吴宗刚 on 2018/6/14.
//

#include "StringUtilsScene.h"

bool StringUtilsScene::init() {
    if (!Scene::init()) {

        return false;
    }

    for (int i = 0; i < 10; ++i) {

        std::string name = StringUtils::format("hello %d", i);
        CCLOG("%s",name.c_str());
    }
    return true;
}
