//
// Created by 吴宗刚 on 2018/7/21.
//

#include "TableItemView.h"

bool TableItemView::init() {
    if (!Node::init()) {
        return false;
    }


    auto draw = DrawNode::create();
    addChild(draw);

    auto image = Sprite::create("ccicon.png");
    image->setAnchorPoint(Vec2::ZERO);
    image->setPosition(Vec2::ZERO);
    addChild(image);

    Rect r = image->getBoundingBox();
    draw->drawRoundedRect(Vec2(r.getMinX(), r.getMinY()), Vec2(r.getMaxX(), r.getMaxY()), 30, 10000,
                          Color4F::RED);


    auto string = StringUtils::format("%d", _index);

    auto indexLabel = Label::create(string, "fonts/arial.ttf", 30);
    indexLabel->setName("index");
    indexLabel->setAnchorPoint(Vec2::ZERO);
    indexLabel->setPosition(Vec2::ZERO);
    addChild(indexLabel);
    return true;

}

TableItemView *TableItemView::newInstance(int index) {

    auto item = new TableItemView();
    item->_index = index;
    if (item->init()) {

        item->autorelease();
        return item;
    } else {

        delete item;
        return nullptr;
    }

}

void TableItemView::update(int index) {


    Label *indexLabel = dynamic_cast<Label *>(getChildByName("index"));
    auto string = StringUtils::format("%d", index);
    indexLabel->setString(string);
}

