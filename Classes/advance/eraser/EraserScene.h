//
// Created by 吴宗刚 on 2018/6/13.
//

#ifndef PROJ_ANDROID_ERASERSCENE_H
#define PROJ_ANDROID_ERASERSCENE_H

#include "cocos2d.h"

USING_NS_CC;

class EraserScene : public Scene {

public:
    CREATE_FUNC(EraserScene)

    bool init() override;

    void addTouchEventListener();

};


#endif //PROJ_ANDROID_ERASERSCENE_H
