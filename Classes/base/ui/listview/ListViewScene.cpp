//
// Created by 吴宗刚 on 2018/6/14.
//

#include "ListViewScene.h"
#include "cocos/ui/UIListView.h"
#include "cocos/ui/UIButton.h"

using namespace ui;

bool ListViewScene::init() {
    if (!BaseScene::init()) {
        return false;
    }

    auto button1 = generateButton();
    auto button2 = generateButton();
    auto button3 = generateButton();
    auto button4 = generateButton();
    auto button5 = generateButton();

    // 水平
    auto layout = Layout::create();
    layout->setLayoutType(Layout::Type::HORIZONTAL);
    layout->setContentSize(Size(_contentSize.width,
                                button1->getContentSize().height));
    layout->setPosition(Vec2::ZERO);

    layout->addChild(button1);
    layout->addChild(button2);
    layout->addChild(button3);
    layout->addChild(button4);
    layout->addChild(button5);

    // 列表
    ListView *listView = ListView::create();
    listView->setDirection(ScrollView::Direction::VERTICAL);
    listView->setContentSize(_contentSize);
    listView->setPosition(Vec2::ZERO);
    addChild(listView);

    listView->setItemModel(layout);

    for (int i = 0; i < 10; i++) {

        Widget *item = layout->clone();
        item->setTag(i);
        listView->pushBackCustomItem(item);
    }
    return true;
}

void ListViewScene::onButtonClicked(Ref *ref) {

}

Button *ListViewScene::generateButton() {

    auto button = Button::create("animationbuttonnormal.png", "animationbuttonpressed.png");
    button->setContentSize(
            Size((_contentSize.width - 20) / 5 - 20, button->getContentSize().height));
    button->setUnifySizeEnabled(true);
    button->setScale9Enabled(true);
    button->ignoreContentAdaptWithSize(false);

    auto params = LinearLayoutParameter::create();
    params->setMargin(Margin(20, 0, 0, 0));
    button->setLayoutParameter(params);

    return button;
}
