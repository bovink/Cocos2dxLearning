//
// Created by 吴宗刚 on 2018/6/13.
//

#include "BaseScene.h"

bool BaseScene::init() {
    if (!Scene::init()) {

        return false;
    }

    addKeyboardEventListener();

    return true;
}

void BaseScene::addKeyboardEventListener() {

    // 监听键盘事件
    auto listener = EventListenerKeyboard::create();

    listener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event *event) {

        CCLOG("keycode %d pressed", keyCode);
        JniHelper::callStaticVoidMethod("org/cocos2dx/cpp/AppActivity",
                                        "changedActivityOrientation", 2);
        Director::getInstance()->popScene();
    };

    listener->onKeyReleased = [](EventKeyboard::KeyCode keyCode, Event *event) {

        CCLOG("keycode %d released", keyCode);
    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
