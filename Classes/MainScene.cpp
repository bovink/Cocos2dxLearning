//
// Created by 吴宗刚 on 2018/6/14.
//

#include "MainScene.h"

bool MainScene::init() {
    if (!Scene::init()) {

        return false;
    }
    CCLOG("init main scene");

//    Text *text = Text::create("test", "fonts/arial.ttf", 30);
//    text->setName("title");
    Button *button = Button::create("HelloWorld.png");
    button->setName("title");
//    text->setPosition(Vec2(_contentSize.width / 2, _contentSize.height / 2));
//
//    text->setString("hello world");
//    this->addChild(text);

    Layout *layout = Layout::create();
    layout->setLayoutType(Layout::Type::VERTICAL);
    layout->setContentSize(button->getContentSize());
    layout->setPosition(Vec2::ZERO);
    layout->addChild(button);

    ListView *listView = ListView::create();
    listView->setDirection(ScrollView::Direction::VERTICAL);
    listView->setContentSize(_contentSize);
    listView->setPosition(Vec2::ZERO);
    this->addChild(listView);

    listView->setItemModel(layout);

    std::vector<const std::string> titles;
    titles.push_back("test1");
    titles.push_back("test2");

    for (std::string title : titles) {

        Widget *item = layout->clone();
        Button *titleText = dynamic_cast<Button *>(item->getChildByName("title"));
        titleText->setTitleText(title);
//        titleText->setString(title);
        listView->pushBackCustomItem(item);
    }


    return true;
}
