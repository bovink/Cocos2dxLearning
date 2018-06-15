//
// Created by 吴宗刚 on 2018/6/13.
//

#ifndef PROJ_ANDROID_BASESCENE_H
#define PROJ_ANDROID_BASESCENE_H


#include "cocos2d.h"

USING_NS_CC;

class BaseScene : public Scene {
public:
    bool init() override;

    CREATE_FUNC(BaseScene)

private:
    void addKeyboardEventListener();

};


#endif //PROJ_ANDROID_BASESCENE_H
