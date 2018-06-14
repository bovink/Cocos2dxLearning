//
// Created by 吴宗刚 on 2018/6/13.
//

#include "CustomViewCell.h"

#include "cocos/ui/CocosGUI.h"

using namespace ui;

void CustomViewCell::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) {
    Node::draw(renderer, transform, flags);
}

bool CustomViewCell::init() {
    if (!Node::init()) {
        return false;
    }

    CCLOG("init cell %d", this->_id);

    Button* button = Button::create("ccicon.png");
    button->setAnchorPoint(Vec2::ZERO);
    button->setSwallowTouches(false);

    button->addClickEventListener([](Ref* ref) {

        CCLOG("button HighLight");
    });


    this->addChild(button);

    return true;
}

void CustomViewCell::sayhi() {
    CCLOG("reset button");
}

CustomViewCell::CustomViewCell(ssize_t _id) : _id(_id) {

    init();
}

void CustomViewCell::updateCell(ssize_t id) {

}


