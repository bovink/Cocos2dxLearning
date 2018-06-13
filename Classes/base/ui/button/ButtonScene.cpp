//
// Created by 吴宗刚 on 2018/6/13.
//

#include "ButtonScene.h"
#include "cocos/ui/CocosGUI.h"

using namespace ui;

bool ButtonScene::init() {

    if (!Scene::init()) {
        return false;
    }
    float _contentSizeWidth = getContentSize().width;
    float _contentSizeHeight = getContentSize().height;


    auto button = Button::create("animationbuttonnormal.png", "nimationbuttonpressed.png","HelloWorld.png");
    button->setPosition(Vec2(_contentSizeWidth / 2, _contentSizeHeight / 2));

    // 点击事件
    button->addClickEventListener([](Ref *ref) {

        CCLOG("click button");
    });

    // 触摸事件
    button->addTouchEventListener([](Ref *ref, Widget::TouchEventType type) {
        Button *clickButton;
        switch (type) {
            case Widget::TouchEventType::BEGAN:
                CCLOG("touch begin");
                break;
            case Widget::TouchEventType::MOVED:
                CCLOG("touch moved");
                break;
            case Widget::TouchEventType::ENDED:
                clickButton = dynamic_cast<Button *>(ref);
                // 设置不可点击
                clickButton->setTouchEnabled(false);
                // 设置图片
                clickButton->setBright(false);
                CCLOG("touch ended");
                break;
            case Widget::TouchEventType::CANCELED:
                CCLOG("touch canceled");
                break;
        }
    });

    this->addChild(button);

    return true;
}
