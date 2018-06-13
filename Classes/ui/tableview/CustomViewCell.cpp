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

    CCLOG("init cell %d",this->_id);

    auto imageView = ImageView::create("ccicon.png");
    imageView->setPosition(Vec2(getContentSize().width / 2, getContentSize().height / 2));
    this->addChild(imageView);

    return true;
}

CustomViewCell::CustomViewCell(ssize_t _id) : _id(_id) {

    init();
}

void CustomViewCell::updateCell(ssize_t id) {

}


