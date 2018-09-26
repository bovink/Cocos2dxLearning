//
// Created by 吴宗刚 on 2018/7/16.
//

#include "DrawNodeScene.h"
#include "cocos/ui/UIImageView.h"

using namespace ui;

bool DrawNodeScene::init() {
    if (!BaseScene::init()) {
        return false;
    }

//    auto helloWorld = ImageView::create("HelloWorld.png");
//    helloWorld->setPosition(_contentSize / 2);
//    addChild(helloWorld);
//
//    Rect r = helloWorld->getBoundingBox();
//
//
//    auto line = DrawNode::create();
//    line->drawSolidRoundedRect(Vec2(r.getMinX() - 20, r.getMinY() - 20),
//                               Vec2(r.getMaxX() + 20, r.getMaxY() + 20), 20,
//                               10000, Color4F::WHITE);
//    line->setPosition(0, 0);
//    addChild(line);

    __CCLOGWITHFUNCTION("contentSize:%f,%f", _contentSize.width, _contentSize.height);
    scale9Sprite = Scale9Sprite::create(Rect(0, 1136 - 500, 640, 500), "ps_game10_bj.png");
    scale9Sprite->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
    scale9Sprite->setContentSize(Size(640, 1136));
    scale9Sprite->setPosition(Vec2(0, _contentSize.height));
//    scale9Sprite->setPosition(_contentSize / 2);
    addChild(scale9Sprite);

    auto increaseWidth = Button::create("animationbuttonnormal.png");
    increaseWidth->setTitleText("width");
    increaseWidth->setTitleFontSize(30);
    increaseWidth->addClickEventListener([&](Ref *ref) {
        scale9Sprite->setContentSize(Size(scale9Sprite->getContentSize().width + 5,
                                          scale9Sprite->getContentSize().height));
    });
    increaseWidth->setPosition(Vec2(_contentSize.width / 2, _contentSize.height - 100));
    addChild(increaseWidth);

    auto increaseHeight = Button::create("animationbuttonnormal.png");
    increaseHeight->setTitleText("height");
    increaseHeight->setTitleFontSize(30);
    increaseHeight->addClickEventListener([&](Ref *ref) {
        scale9Sprite->setContentSize(Size(scale9Sprite->getContentSize().width,
                                          scale9Sprite->getContentSize().height - 5));
    });
    increaseHeight->setPosition(Vec2(_contentSize.width / 2, 100));
    addChild(increaseHeight);


    return true;
}
