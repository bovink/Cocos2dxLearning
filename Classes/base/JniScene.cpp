//
// Created by 吴宗刚 on 2018/7/12.
//

#include "JniScene.h"

#include "cocos/ui/UIButton.h"
#include "cocos/ui/UILayoutParameter.h"
#include "cocos/ui/UILayout.h"

using namespace ui;

bool JniScene::init() {
    if (!BaseScene::init()) {
        return false;
    }

    auto param = LinearLayoutParameter::create();
    param->setGravity(LinearLayoutParameter::LinearGravity::CENTER_VERTICAL);
    param->setMargin(Margin(20, 0, 0, 0));

    auto start = Button::create("animationbuttonnormal.png");
    start->setTitleText("start");
    start->addClickEventListener(CC_CALLBACK_1(JniScene::onStartClick, this));
    start->setLayoutParameter(param);

    auto stop = Button::create("animationbuttonnormal.png");
    stop->setTitleText("stop");
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
    JniHelper::callStaticVoidMethod("org/cocos2dx/cpp/RecordHelper",
                                    "startRecord");
#endif
}

void JniScene::onStopClick(Ref *ref) {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelper::callStaticVoidMethod("org/cocos2dx/cpp/RecordHelper",
                                    "stopRecord");
#endif
}

void JniScene::onPlayClick(Ref *ref) {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelper::callStaticVoidMethod("org/cocos2dx/cpp/RecordHelper",
                                    "playAudio");
#endif
}

void JniScene::onProcessClick(Ref *ref) {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

    JniHelper::callStaticVoidMethod("org/cocos2dx/cpp/RecordHelper",
                                    "process");
#endif
}
