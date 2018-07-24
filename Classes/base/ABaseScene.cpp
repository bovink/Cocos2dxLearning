//
// Created by 吴宗刚 on 2018/7/24.
//

#include "ABaseScene.h"

bool ABaseScene::init() {
    if (!Scene::init()) {

        return false;
    }

    __CCLOGWITHFUNCTION("init");
    initViews();

    return true;
}
