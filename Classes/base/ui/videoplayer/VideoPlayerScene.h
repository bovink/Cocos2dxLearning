//
// Created by bovink on 2018/6/4.
//

#ifndef PROJ_ANDROID_TESTVIDEOPLAYER_H
#define PROJ_ANDROID_TESTVIDEOPLAYER_H

#include "BaseScene.h"
#include "cocos2d.h"
#include "cocos/ui/CocosGUI.h"

USING_NS_CC;
using namespace experimental::ui;

class TestVideoPlayer : public BaseScene {

public:
    // 方法

    bool init() override;

    CREATE_FUNC(TestVideoPlayer)

    void update(float delta) override;

private:
    // 方法



private:
    // 属性

    const std::string _NAME_VIDEO = "video";

};


#endif //PROJ_ANDROID_TESTVIDEOPLAYER_H
