//
// Created by 吴宗刚 on 2018/7/12.
//

#include <widget/Toast.h>
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

    auto content = Layout::create();
    content->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
    content->setBackGroundColor(Color3B::WHITE);
    content->setContentSize(_contentSize);
    addChild(content);


    auto toast = Toast::newInstance("测试消息测试消息测试消息测试消息测试消息测试消息");
    toast->setPosition(Vec2::ZERO);
    content->addChild(toast);


}
