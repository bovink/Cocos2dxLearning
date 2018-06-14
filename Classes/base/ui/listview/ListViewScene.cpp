//
// Created by 吴宗刚 on 2018/6/14.
//

#include "ListViewScene.h"
#include "cocos/ui/UIListView.h"

using namespace ui;

bool ListViewScene::init() {
    if (!Scene::init()) {
        return false;
    }
    float _contentSizeWidth = getContentSize().width;
    float _contentSizeHeight = getContentSize().height;

    auto listView = ListView::create();
    listView->setDirection(ScrollView::Direction::HORIZONTAL);
    listView->setContentSize(Size(getContentSize().width, 120));
    listView->setPosition(Vec2(_contentSizeWidth / 2, _contentSizeHeight / 2));
    this->addChild(listView);


    return true;
}
