//
// Created by 吴宗刚 on 2018/6/14.
//

#include <base/ui/listview/ListViewScene.h>
#include <base/userdefault/UserDefaultScene.h>
#include <base/JniScene.h>
#include "MainScene.h"

using namespace std;

bool MainScene::init() {
    if (!Scene::init()) {

        return false;
    }

    initListView();

    initListData();

    return true;
}

void MainScene::initListView() {

    auto _layoutItem = generateLayout();

    ListView *listView = ListView::create();
    listView->setName(_NAME_LIST);
    listView->setDirection(ScrollView::Direction::VERTICAL);
    listView->setContentSize(_contentSize);
    listView->setPosition(Vec2::ZERO);
    addChild(listView);

    listView->setItemModel(_layoutItem);
}

void MainScene::initListData() {

    ListView *listView = dynamic_cast<ListView *>(getChildByName(_NAME_LIST));

    std::vector<const std::string> titles;
    titles.push_back("listview");
    titles.push_back("User Default");
    titles.push_back("JNI");
    titles.push_back("touch4");
    titles.push_back("touch5");

    for (int i = 0; i < titles.size() - 1; i++) {
        string title = titles.at(i);

        Widget *item = generateLayout();
        item->setTouchEnabled(true);
        item->addClickEventListener(CC_CALLBACK_1(MainScene::onItemClickEvent, this));
        item->setTag(i);
        Text *titleText = dynamic_cast<Text *>(item->getChildByName(_NAME_TITLE));
        titleText->setString(title);
        listView->pushBackCustomItem(item);
    }

    listView->setItemsMargin(20);
}

Layout *MainScene::generateLayout() {

    auto *text = Text::create("example", "fonts/arial.ttf", 80);
    text->setName(_NAME_TITLE);

    auto params = LinearLayoutParameter::create();
    params->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    text->setLayoutParameter(params);

    auto _layoutItem = Layout::create();
    _layoutItem->setLayoutType(Layout::Type::VERTICAL);
    _layoutItem->setPosition(Vec2::ZERO);
    _layoutItem->setContentSize(Size(_contentSize.width, text->getContentSize().height));
    _layoutItem->addChild(text);

    return _layoutItem;
}

void MainScene::onItemClickEvent(Ref* ref) {
    Layout *layout = dynamic_cast<Layout *>(ref);
    int tag = layout->getTag();

    Scene* scene;
    switch (tag) {
        case 0:
            scene = ListViewScene::create();
            _director->pushScene(scene);
            break;
        case 1:
            scene = UserDefaultScene::create();
            _director->pushScene(scene);
            break;
        case 2:
            scene = JniScene::create();
            _director->pushScene(scene);
            break;
        case 3:
            break;
        default:
            break;
    }
}


