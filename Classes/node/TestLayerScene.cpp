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

    // 监听键盘事件
    auto listener = EventListenerKeyboard::create();

    listener->onKeyPressed = CC_CALLBACK_2(TestLayerScene::onKeyPressed, this);

    listener->onKeyReleased = CC_CALLBACK_2(TestLayerScene::onKeyReleased, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

void TestLayerScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {

    CCLOG("keycode %d pressed", keyCode);
    Director::getInstance()->popScene();
}

void TestLayerScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {

    CCLOG("keycode %d released", keyCode);
}



