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

};

class TestListView : public BaseScene {

public:

    CREATE_FUNC(TestListView)

    bool init() override;

    int index = 0;
    ListView *listView;

};

class SizeTest : public BaseScene {

public:

    CREATE_FUNC(SizeTest)

    bool init() override;

};

class MarqueeTextTest: public BaseScene {

public:

    CREATE_FUNC(MarqueeTextTest)

    bool init() override;
};


#endif //PROJ_ANDROID_TESTBUTTONSCENE_H
