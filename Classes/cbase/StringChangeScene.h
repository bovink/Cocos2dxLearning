//
// Created by bovink on 2018/6/5.
//

#ifndef PROJ_ANDROID_STRINGCHANGESCENE_H
#define PROJ_ANDROID_STRINGCHANGESCENE_H


#include <base/BaseScene.h>

class StringChangeScene : public BaseScene {
public:
    bool init() override;

    CREATE_FUNC(StringChangeScene);

private:
    void stringToChar();

    void charToString();

    void charArrayToString();

    void stringToCharArray();

    void ptrCharVectorToString();
private:

};


#endif //PROJ_ANDROID_STRINGCHANGESCENE_H
