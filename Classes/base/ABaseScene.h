//
// Created by 吴宗刚 on 2018/7/24.
//

#ifndef PROJ_ANDROID_ABASESCENE_H
#define PROJ_ANDROID_ABASESCENE_H

#include "cocos2d.h"
#include "cocos/ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class ABaseScene : public Scene {

public:

    bool init() override;

    virtual void initViews() = 0;



};


#endif //PROJ_ANDROID_ABASESCENE_H
