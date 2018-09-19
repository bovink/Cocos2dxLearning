//
// Created by 吴宗刚 on 2018/7/12.
//

#include "JniScene.h"

#include "cocos/ui/UIButton.h"
#include "cocos/ui/UILayoutParameter.h"
#include "cocos/ui/UILayout.h"
#include "CallNativeInterface.h"

using namespace ui;

bool JniScene::init() {
    if (!BaseScene::init()) {
        return false;
    }

    auto param = LinearLayoutParameter::create();
    param->setGravity(LinearLayoutParameter::LinearGravity::CENTER_VERTICAL);
    param->setMargin(Margin(20, 0, 0, 0));

    auto start = Button::create("animationbuttonnormal.png");
    start->setTitleText("hide");
    start->setTitleFontSize(30);
    start->addClickEventListener(CC_CALLBACK_1(JniScene::onStartClick, this));
    start->setLayoutParameter(param);

    auto stop = Button::create("animationbuttonnormal.png");
    stop->setTitleText("show");
    stop->setTitleFontSize(30);
    stop->addClickEventListener(CC_CALLBACK_1(JniScene::onStopClick, this));
    stop->setLayoutParameter(param);

    auto play = Button::create("animationbuttonnormal.png");
    play->setTitleText("play");
    play->addClickEventListener(CC_CALLBACK_1(JniScene::onPlayClick, this));
    play->setLayoutParameter(param);

    auto process = Button::create("animationbuttonnormal.png");
    process->setTitleText("process");
    process->addClickEventListener(CC_CALLBACK_1(JniScene::onProcessClick, this));
    process->setLayoutParameter(param);

    auto horizon = Layout::create();
    horizon->setLayoutType(Layout::Type::HORIZONTAL);
    horizon->setPosition(Vec2::ZERO);
    horizon->setContentSize(_contentSize);

    horizon->addChild(start);
    horizon->addChild(stop);
    horizon->addChild(play);
    horizon->addChild(process);

    addChild(horizon);


    return true;
}

void JniScene::onStartClick(Ref *ref) {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelper::callStaticVoidMethod("org/cocos2dx/cpp/AppActivity",
                                    "hide");
#endif
    _director->popScene();
}

void JniScene::onStopClick(Ref *ref) {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelper::callStaticVoidMethod("org/cocos2dx/cpp/AppActivity",
                                    "show");
#endif
    _director->popScene();
}

void JniScene::onPlayClick(Ref *ref) {

    auto callNative = new CallNativeInterface();
    callNative->printInfoFromNative();
}

void JniScene::onProcessClick(Ref *ref) {

    auto callNative = new CallNativeInterface();
    callNative->showToast();
}
