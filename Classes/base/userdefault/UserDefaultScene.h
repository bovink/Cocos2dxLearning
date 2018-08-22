//
// Created by 吴宗刚 on 2018/7/12.
//

#ifndef PROJ_ANDROID_USERDEFAULTSCENE_H
#define PROJ_ANDROID_USERDEFAULTSCENE_H


#include "BaseScene.h"

class UserDefaultScene : public BaseScene {

public:

    bool init() override;

    CREATE_FUNC(UserDefaultScene)
private:

    void testSaveData();

    Image* img;
    unsigned char* data;
    Texture2D* texture;
    Sprite* sprite;

    void setColor4B(int x, int y, Color4B color, unsigned char *data);

};


#endif //PROJ_ANDROID_USERDEFAULTSCENE_H
