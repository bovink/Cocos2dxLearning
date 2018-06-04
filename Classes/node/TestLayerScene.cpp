//
// Created by bovink on 2018/6/4.
//

#include "TestLayerScene.h"

bool TestLayerScene::init() {
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::create();
    label->setString("hello,this is test");
    label->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
    addChild(label);

    return true;
}

