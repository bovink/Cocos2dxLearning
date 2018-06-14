//
// Created by 吴宗刚 on 2018/6/14.
//

#include "MainScene.h"

bool MainScene::init() {
    if (!Scene::init()) {

        return false;
    }

    Layout *layout = Layout::create();
    layout->setLayoutType(Layout::Type::VERTICAL);
    layout->setContentSize(getContentSize());
    layout->setPosition(Vec2(getContentSize() / 2));

    Button *button1 = Button::create("animationbuttonnormal.png", "animationbuttonpressed.png");
    layout->addChild(button1);

    LinearLayoutParameter *button1Param = LinearLayoutParameter::create();
    button1->setLayoutParameter(button1Param);
    button1Param->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);

    Button *button2 = Button::create("animationbuttonnormal.png", "animationbuttonpressed.png");
    layout->addChild(button2);

    LinearLayoutParameter *button2Param = LinearLayoutParameter::create();
    button2->setLayoutParameter(button2Param);
    button2Param->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);


    return true;
}
