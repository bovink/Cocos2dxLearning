//
// Created by 吴宗刚 on 2018/6/12.
//

#ifndef PROJ_ANDROID_TESTIMAGEVIEW_H
#define PROJ_ANDROID_TESTIMAGEVIEW_H


#include "BaseScene.h"

class TestImageView {

};

class TestFrameAnimation : public BaseScene {

public:

    CREATE_FUNC(TestFrameAnimation)

    bool init() override;

private:

    void initViews();

};


#endif //PROJ_ANDROID_TESTIMAGEVIEW_H
