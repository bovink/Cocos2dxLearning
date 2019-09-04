//
// Created by 吴宗刚 on 2019/9/3.
//

#include "ListScene.h"

bool ListScene::init() {
    if (!Scene::init()) {
        return false;
    }
    UIPackage::addPackage("list");

    gRoot = GRoot::create(this, 0);
    gRoot->retain();
    // 获取主视图
    __CCLOGWITHFUNCTION("加载新p内容");
    auto view = UIPackage::createObject("list", "list")->as<GComponent>();

    gRoot->addChild(view);
    demoContainer = view->getChild("n3")->as<GComponent>();
    _cc = view->getController("c1");

    int cnt = view->numChildren();
    for (int i = 0; i < cnt; i++)
    {
        GObject* obj = view->getChildAt(i);
        if (obj->getGroup() != nullptr && obj->getGroup()->name.compare("btns") == 0)
            obj->addClickListener(CC_CALLBACK_1(ListScene::runDemo, this));
    }

    return true;
}

void ListScene::renderListItem(int index, GObject* obj)
{
    GButton *button = obj->as<GButton>();
    button->setTitle(StringUtils::format("按钮%d", index + 1));

}

void ListScene::runDemo(EventContext *context) {

    GObject *object = dynamic_cast<GObject *>(context->getSender());
    __CCLOGWITHFUNCTION("name:%s",object->name.c_str());


    GComponent* obj = UIPackage::createObject("list", "normallist")->as<GComponent>();

    demoContainer->addChild(obj);
    _cc->setSelectedIndex(1);

    auto list = obj->getChild("listview")->as<GList>();
    list->itemRenderer = CC_CALLBACK_2(ListScene::renderListItem, this);
    list->setVirtual();
    list->setNumItems(1000);

}
