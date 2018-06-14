//
// Created by 吴宗刚 on 2018/6/14.
//

#include "ListViewScene.h"
#include "cocos/ui/UIListView.h"
#include "cocos/ui/UIButton.h"

using namespace ui;

bool ListViewScene::init() {
    if (!Scene::init()) {
        return false;
    }
    float _contentSizeWidth = getContentSize().width;
    float _contentSizeHeight = getContentSize().height;

    auto listView = ListView::create();
    listView->setDirection(ScrollView::Direction::VERTICAL);
    listView->setContentSize(Size(getContentSize().width, getContentSize().height));
    listView->setPosition(Vec2(0, 0));
    this->addChild(listView);

    Button *default_button = Button::create("animationbuttonnormal.png",
                                            "animationbuttonpressed.png");
    default_button->setName("Title Button");

    Layout *default_item = Layout::create();
    default_item->setTouchEnabled(true);
    default_item->setContentSize(default_button->getContentSize());
    default_button->setPosition(Vec2(default_item->getContentSize() / 2.0f));
    default_item->addChild(default_button);

    // set model
    listView->setItemModel(default_item);

    // set all items layout gravity
//    listView->setGravity(ListView::Gravity::CENTER_VERTICAL);

    std::vector<std::string> _array;
    for (int i = 0; i < 20; ++i) {
        std::string ccstr = StringUtils::format("listview_item_%d", i);
        _array.push_back(ccstr);
    }

    //initial the data
    for (int i = 0; i < 20; ++i) {
        Widget *item = default_item->clone();
        item->setTag(i);
        Button *btn = (Button *) item->getChildByName("Title Button");
        btn->setTitleText(_array.at(i));
        listView->pushBackCustomItem(item);
    }
    return true;
}
