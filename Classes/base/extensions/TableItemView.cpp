//
// Created by 吴宗刚 on 2018/7/21.
//

#include "TableItemView.h"

bool TableItemView::init() {
    if (!Node::init()) {
        return false;
    }

    auto image = Sprite::create("ccicon.png");
    image->setAnchorPoint(Vec2::ZERO);
    image->setPosition(Vec2::ZERO);
    addChild(image);


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

