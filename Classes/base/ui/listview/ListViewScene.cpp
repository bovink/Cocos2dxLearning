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
    listView->setContentSize(Size(400, getContentSize().height));
//    listView->setDirection(ScrollView::Direction::HORIZONTAL);
//    listView->setContentSize(Size(getContentSize().width, 200));
    listView->setPosition(Vec2(0, 0));
    listView->setTag(123);
    this->addChild(listView);

    Button *default_button = Button::create("animationbuttonnormal.png",
                                            "animationbuttonpressed.png");
    default_button->setName("Title Button");

    Button *default_button2 = Button::create("animationbuttonnormal.png",
                                             "animationbuttonpressed.png");
    default_button2->setName("Title Button2");

    Layout *default_item = Layout::create();
    default_item->setTouchEnabled(true);

    default_item->setContentSize(Size(default_button->getContentSize().width * 2,
                                      default_button->getContentSize().height));
    default_button->setPosition(Vec2(default_button->getContentSize() / 2));
    default_button2->setPosition(Vec2(default_button->getContentSize().width * 3 / 2,
                                      default_button->getContentSize().height / 2));

    default_item->addChild(default_button);
    default_item->addChild(default_button2);

    // set model
    listView->setItemModel(default_item);


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
        btn->setTitleFontSize(20);
        btn->addClickEventListener(CC_CALLBACK_1(ListViewScene::onButtonClicked, this));
        listView->pushBackCustomItem(item);
    }
    return true;
}

void ListViewScene::onButtonClicked(Ref *ref) {
    ListView *listView = dynamic_cast<ListView *>(this->getChildByTag(123));
    for (Widget *item :listView->getItems()) {

        Button *btn = (Button *) item->getChildByName("Title Button");
        btn->setBrightStyle(Button::BrightStyle::NORMAL);
    }

    Button *button = dynamic_cast<Button *>(ref);
    button->setBrightStyle(Button::BrightStyle::HIGHLIGHT);

}
