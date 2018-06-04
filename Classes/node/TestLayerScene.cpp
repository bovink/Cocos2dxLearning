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

    auto bottomLayer = LayerColor::create(Color4B(255, 255, 255, 255), 720,
                                    1280);
    bottomLayer->setPosition(Vec2(0, 0));
    addChild(bottomLayer);

    // 添加带有颜色的层
    auto layer = LayerColor::create(Color4B(192, 0, 0, 255), 700,
                                    1260);
    layer->setPosition(Vec2(10, 10));
    addChild(layer);

    // 添加标签
    auto label = Label::create();
    label->setString("hello,this is test");
    label->setPosition(Vec2(getContentSize().width / 2.0f, getContentSize().height / 2.0f));
    addChild(label);

    addTouchEventListener();

    addKeyboardEventListener();

    return true;
}

void TestLayerScene::addTouchEventListener() {

    auto listener = EventListenerTouchOneByOne::create();

    listener->onTouchBegan = [](Touch *touch, Event *event) {

        return true;
    };

    listener->onTouchMoved = [](Touch *touch, Event *event) {

        Vec2 location = touch->getLocation();
        CCLOG("x:%f, y:%f", location.x, location.y);
    };

    listener->onTouchEnded = [](Touch *touch, Event *event) {

    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void TestLayerScene::addKeyboardEventListener() {

    // 监听键盘事件
    auto listener = EventListenerKeyboard::create();

    listener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event *event) {

        CCLOG("keycode %d pressed", keyCode);
        Director::getInstance()->popScene();
    };

    listener->onKeyReleased = [](EventKeyboard::KeyCode keyCode, Event *event) {

        CCLOG("keycode %d released", keyCode);
    };

//    listener->onKeyPressed = CC_CALLBACK_2(TestLayerScene::onKeyPressed, this);
//
//    listener->onKeyReleased = CC_CALLBACK_2(TestLayerScene::onKeyReleased, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void TestLayerScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {

    CCLOG("keycode %d pressed", keyCode);
}

void TestLayerScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {

}



