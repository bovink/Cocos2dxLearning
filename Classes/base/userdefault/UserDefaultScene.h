//
// Created by 吴宗刚 on 2018/7/12.
//

#ifndef PROJ_ANDROID_USERDEFAULTSCENE_H
#define PROJ_ANDROID_USERDEFAULTSCENE_H


#include <base/BaseScene.h>

class UserDefaultScene : public BaseScene {

public:

    bool init() override;

    CREATE_FUNC(UserDefaultScene)
private:

    void testSaveData();


};


#endif //PROJ_ANDROID_USERDEFAULTSCENE_H
