//
// Created by 吴宗刚 on 2019/9/3.
//

#ifndef PROJ_ANDROID_LISTSCENE_H
#define PROJ_ANDROID_LISTSCENE_H

#include "cocos2d.h"
#include "cocos/ui/CocosGUI.h"
#include <string>
#include <vector>

USING_NS_CC;

#include "FairyGUI.h"

USING_NS_FGUI;
using namespace cocos2d::ui;
using namespace experimental::ui;
using namespace std;

class ListScene : public Scene {

public:

    CREATE_FUNC(ListScene)

    bool init() override;

private:
    void renderListItem(int index, GObject *obj);

    void runDemo(EventContext *context);

private:
    GRoot *gRoot;
    GController* _cc;

    GComponent *demoContainer;

};

class TestCacheRemoveScene : public Scene {
public:

    TestCacheRemoveScene();

    virtual ~TestCacheRemoveScene();

    CREATE_FUNC(TestCacheRemoveScene)

    bool init() override;

private:

    void addImageAsync();

    void removeImageCache();

    void unbindImageAsync();

    void removeUnusedCache();
private:
    GRoot *gRoot;

    GComponent* view;

    string cachePicName;
    vector<string> removeTextures;
    bool needRemove  = false;
};


#endif //PROJ_ANDROID_LISTSCENE_H
