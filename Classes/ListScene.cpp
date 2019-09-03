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
    return true;
}
