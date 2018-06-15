//
// Created by 吴宗刚 on 2018/6/15.
//

#include "TransitionTestScene.h"
#include "cocos/ui/UIButton.h"

using namespace ui;

bool TransitionTestScene::init() {
    if (!BaseScene::init()) {

        return false;
    }

    auto layer = LayerColor::create(backgroundColor);
    this->addChild(layer);

    auto button = Button::create("HelloWorld.png");
    button->setPosition(Vec2(_contentSize.width, 100));
    button->addClickEventListener(CC_CALLBACK_1(TransitionTestScene::onPushSceneButtonClick, this));
    this->addChild(button);


    return true;
}

TransitionTestScene *TransitionTestScene::newInstance(Color4B color4B) {
    TransitionTestScene *scene = new TransitionTestScene();
    scene->backgroundColor = color4B;

    if (scene->init()) {

        scene->autorelease();
        return scene;
    } else {

        delete scene;
        return nullptr;
    }
}

void TransitionTestScene::onPushSceneButtonClick(Ref *ref) {

    Director::getInstance()->replaceScene(
            TransitionZoomFlipX::create(0.5, this->newInstance(Color4B(192, 0, 0, 255)),
                                        TransitionScene::Orientation::RIGHT_OVER));
}
