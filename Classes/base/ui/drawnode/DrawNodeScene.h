//
// Created by 吴宗刚 on 2018/7/16.
//

#ifndef PROJ_ANDROID_DRAWNODESCENE_H
#define PROJ_ANDROID_DRAWNODESCENE_H

#include "BaseScene.h"

class DrawNodeScene : public BaseScene {

public:

    CREATE_FUNC(DrawNodeScene)

    bool init() override;

private:


    Scale9Sprite *scale9Sprite;
};


#endif //PROJ_ANDROID_DRAWNODESCENE_H
