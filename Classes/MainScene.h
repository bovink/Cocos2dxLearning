//
// Created by 吴宗刚 on 2018/6/14.
//

#ifndef PROJ_ANDROID_MAINSCENE_H
#define PROJ_ANDROID_MAINSCENE_H

#include "cocos2d.h"
#include "cocos/ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class MainScene : public Scene {
public:
    bool init() override;

    CREATE_FUNC(MainScene)

private:

    void initListView();

    void initListData();

    Layout *generateLayout();

    void onItemClickEvent(Ref* ref);

private:

//    Layout* _layoutItem;

    const std::string _NAME_TITLE = "title";
    const std::string _NAME_LIST = "list";
};


#endif //PROJ_ANDROID_MAINSCENE_H
