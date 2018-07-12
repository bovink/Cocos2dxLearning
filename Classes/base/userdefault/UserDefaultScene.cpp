//
// Created by 吴宗刚 on 2018/7/12.
//

#include "UserDefaultScene.h"

bool UserDefaultScene::init() {
    if (!BaseScene::init()) {
        return false;
    }

    testSaveData();

    return true;
}

void UserDefaultScene::testSaveData() {

    bool first = UserDefault::getInstance()->getBoolForKey("isFirstIn", false);
    if (first) {

        __CCLOGWITHFUNCTION("非第一次进");
    } else {

        __CCLOGWITHFUNCTION("第一次进");
        UserDefault::getInstance()->setBoolForKey("isFirstIn", true);
    }


}
