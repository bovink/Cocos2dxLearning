//
// Created by bovink on 2018/6/4.
//

#include "CustomTableCellView.h"

void CustomTableCellView::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) {
    TableViewCell::draw(renderer, transform, flags);
}

bool CustomTableCellView::init() {

    CCLOG("CustomTableCellView::init()");
    auto string = StringUtils::format("%ld", static_cast<long>(this->id));

    for (int i = 0; i < 4; i++) {

        auto sprite = Sprite::create("ccicon.png");
        sprite->setAnchorPoint(Vec2::ZERO);
        sprite->setPosition(Vec2(0 + sprite->getContentSize().width * i, 0));
        this->addChild(sprite);
        vector.pushBack(sprite);

        auto label = Label::createWithSystemFont(string, "Helvetica", 20.0);
        label->setPosition(Vec2::ZERO);
        label->setAnchorPoint(Vec2::ZERO);
        label->setTag(123);
        sprite->addChild(label);
    }

    return true;
}

void CustomTableCellView::updateCell(ssize_t id) {

    for (Sprite *sprite: vector) {

        auto string = StringUtils::format("%ld",
                                          static_cast<long>(vector.getIndex(sprite) + id * 4));

        Label *label = dynamic_cast<Label *>(sprite->getChildByTag(123));
        label->setString(string);
    }


}

CustomTableCellView::CustomTableCellView(ssize_t id) {
    CCLOG("CustomTableCellView(ssize_t id)");

    this->id = id;
    init();
}

