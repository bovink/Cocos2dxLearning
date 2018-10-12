//
// Created by 吴宗刚 on 2018/6/13.
//

#ifndef PROJ_ANDROID_TESTBUTTONSCENE_H
#define PROJ_ANDROID_TESTBUTTONSCENE_H

#include "BaseScene.h"

class ButtonScene : public BaseScene {

public:

    bool init() override;

    CREATE_FUNC(ButtonScene)
};

class TestClipScene : public BaseScene {

public:

    CREATE_FUNC(TestClipScene)

    bool init() override;

    void setColor4B(int x, int y, int width, Color4B color, unsigned char *data);

    bool expectColor4B(int x, int y, int width, Color4B color, unsigned char *data);
};


#endif //PROJ_ANDROID_TESTBUTTONSCENE_H
