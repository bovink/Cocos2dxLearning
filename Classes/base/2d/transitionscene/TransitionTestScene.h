//
// Created by 吴宗刚 on 2018/6/15.
//

#ifndef PROJ_ANDROID_TRANSITIONSCENE_H
#define PROJ_ANDROID_TRANSITIONSCENE_H


#include "../../BaseScene.h"

class TransitionTestScene : public BaseScene {
public:
    bool init() override;

    static TransitionTestScene *newInstance(Color4B color4B);

private:
    void onPushSceneButtonClick(Ref *ref);

private:
    Color4B backgroundColor;

};


#endif //PROJ_ANDROID_TRANSITIONSCENE_H
