//
// Created by bovink on 2018/6/4.
//

#ifndef PROJ_ANDROID_TESTLAYERSCENE_H
#define PROJ_ANDROID_TESTLAYERSCENE_H


#include "cocos2d.h"

USING_NS_CC;

class TestLayerScene : public Scene {

public:

    CREATE_FUNC(TestLayerScene)

    bool init() override;

private:;

    void addTouchEventListener();

    void addKeyboardEventListener();

    // 键盘按键按下事件
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);

    // 键盘按键释放事件
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);
};


#endif //PROJ_ANDROID_TESTLAYERSCENE_H
