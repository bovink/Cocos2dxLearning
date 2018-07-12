//
// Created by 吴宗刚 on 2018/7/12.
//

#ifndef PROJ_ANDROID_JNISCENE_H
#define PROJ_ANDROID_JNISCENE_H


#include "BaseScene.h"

class JniScene : public BaseScene {

public:

    bool init() override;

    CREATE_FUNC(JniScene)

private:

    void onStartClick(Ref *ref);

    void onStopClick(Ref *ref);

    void onPlayClick(Ref *ref);

    void onProcessClick(Ref *ref);
};


#endif //PROJ_ANDROID_JNISCENE_H
