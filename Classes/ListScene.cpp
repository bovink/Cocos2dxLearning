//
// Created by 吴宗刚 on 2019/9/3.
//

#include "ListScene.h"

bool ListScene::init() {
    if (!Scene::init()) {
        return false;
    }
//    UIPackage::addPackage("list");
//
//    gRoot = GRoot::create(this, 0);
//    gRoot->retain();
    // 获取主视图
    __CCLOGWITHFUNCTION("加载新p内容");
//    auto view = UIPackage::createObject("list", "list")->as<GComponent>();
//
//    gRoot->addChild(view);
//    demoContainer = view->getChild("n3")->as<GComponent>();
//    _cc = view->getController("c1");
//
//    int cnt = view->numChildren();
//    for (int i = 0; i < cnt; i++) {
//        GObject *obj = view->getChildAt(i);
//        if (obj->getGroup() != nullptr && obj->getGroup()->name.compare("btns") == 0)
//            obj->addClickListener(CC_CALLBACK_1(ListScene::runDemo, this));
//    }

    return true;
}

void ListScene::renderListItem(int index, GObject *obj) {
    GButton *button = obj->as<GButton>();
    button->setTitle(StringUtils::format("按钮%d", index + 1));

}

void ListScene::runDemo(EventContext *context) {

    GObject *object = dynamic_cast<GObject *>(context->getSender());
    __CCLOGWITHFUNCTION("name:%s", object->name.c_str());


    GComponent *obj = UIPackage::createObject("list", "normallist")->as<GComponent>();

    demoContainer->addChild(obj);
    _cc->setSelectedIndex(1);

    auto list = obj->getChild("listview")->as<GList>();
    list->itemRenderer = CC_CALLBACK_2(ListScene::renderListItem, this);
    list->setVirtual();
    list->setNumItems(1000);

}

bool TestCacheRemoveScene::init() {
    if (!Scene::init()) {
        return false;
    }
    UIPackage::addPackage("test_cache_image");

    gRoot = GRoot::create(this, 0);
    gRoot->retain();
    // 获取主视图
    __CCLOGWITHFUNCTION("TestCacheRemoveScene init");
    view = UIPackage::createObject("test_cache_image", "base")->as<GComponent>();
    view->setSortingOrder(100);
    gRoot->addChild(view);

    view_render = UIPackage::createObject("test_cache_image", "Component2")->as<GComponent>();
    view_render->setPosition(10000, 10000);
    gRoot->addChild(view_render);

    GButton *_btnDeleteBind = view->getChild("btn_delete_bind")->as<GButton>();
    _btnDeleteBind->addClickListener([&](EventContext *) {

        unbindImageAsync();
    });
    GButton *_btnAddImage = view->getChild("btn_add_image")->as<GButton>();
    _btnAddImage->addClickListener([&](EventContext *) {

        addImageAsync();


    });
    GButton *_btnRemoveImage = view->getChild("btn_remove_image")->as<GButton>();
    _btnRemoveImage->addClickListener([&](EventContext *) {


        removeImageCache();
    });

    GButton *_btnAddScene = view->getChild("btn_add_scene")->as<GButton>();
    _btnAddScene->addClickListener([&](EventContext *) {
//        UIPackage::addPackage("the_farm/the_farm");
//
//
//        auto newScene = UIPackage::createObject("the_farm", "backcover")->as<GComponent>();
//        newScene->setSortingOrder(99);
//        newScene->name = "newScene";
//
//        gRoot->addChild(newScene);
        auto screen = RenderTexture::create(_contentSize.width, _contentSize.height);
        screen->begin();
        view_render->getChild("n0")->displayObject()->getParent()->visit();
        screen->end();
        screen->saveToFile("ScreenShot.png", Image::Format::PNG);
        view_render->setVisible(false);

    });
    GButton *_btnDeleteScene = view->getChild("btn_delete_scene")->as<GButton>();
    _btnDeleteScene->addClickListener([&](EventContext *) {
//
//        gRoot->removeChild(gRoot->getChild("newScene"));
//        UIPackage::removePackage("the_farm/the_farm");
        auto path = FileUtils::getInstance()->getWritablePath();
        vector<string> pathList;
        FileUtils::getInstance()->listFilesRecursively(path, &pathList);
        for (int i = 0; i < pathList.size(); ++i) {
            __CCLOGWITHFUNCTION("路径：%s", pathList.at(i).c_str());
        }
        auto icon = path + "ScreenShot.png";
        __CCLOGWITHFUNCTION("加载%s", icon.c_str());
        auto load = view->getChild("load")->as<GLoader>();
        load->setURL(icon);
        gRoot->removeChild(view_render);

    });
    return true;
}

void TestCacheRemoveScene::addImageAsync() {

    Director::getInstance()->getTextureCache()
            ->addImageAsync(cachePicName, [&](Texture2D *tex) {
                auto i = find(removeTextures.begin(), removeTextures.end(), cachePicName);
                if (i != removeTextures.end()) {
                    Director::getInstance()->getTextureCache()->removeTexture(tex);
                    removeTextures.erase(i);
                    return;
                }

//                Director::getInstance()->getTextureCache()->removeTexture(tex);
                string s = Director::getInstance()->getTextureCache()->getCachedTextureInfo();
                __CCLOGWITHFUNCTION("图片缓存完毕");
                __CCLOGWITHFUNCTION("缓存信息:%s", s.c_str());
            });
}

void TestCacheRemoveScene::removeImageCache() {

    __CCLOGWITHFUNCTION("删除缓存");
    Director::getInstance()->getTextureCache()->removeTextureForKey(cachePicName);
}

void TestCacheRemoveScene::unbindImageAsync() {

    __CCLOGWITHFUNCTION("移除绑定");
//    Director::getInstance()->getTextureCache()->unbindImageAsync(cachePicName);

    Director::getInstance()->getTextureCache()->removeTextureForKey(cachePicName);
    removeTextures.push_back(cachePicName);
}

void TestCacheRemoveScene::removeUnusedCache() {
    while (needRemove) {
        for (auto &s:removeTextures) {

            Director::getInstance()->getTextureCache()->removeTextureForKey(s);
            auto i = find(removeTextures.begin(), removeTextures.end(), s);
            removeTextures.erase(i);
        }
        if (removeTextures.size() == 0) {
            needRemove = false;
        }

    }

}

TestCacheRemoveScene::TestCacheRemoveScene() {
    cachePicName = "the_farm/the_farm_atlas7_1.png";
}

TestCacheRemoveScene::~TestCacheRemoveScene() {

    gRoot->release();
}
