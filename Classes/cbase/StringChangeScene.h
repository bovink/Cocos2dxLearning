//
// Created by bovink on 2018/6/5.
//

#ifndef PROJ_ANDROID_STRINGCHANGESCENE_H
#define PROJ_ANDROID_STRINGCHANGESCENE_H

#include "cocos2d.h"

USING_NS_CC;

class StringChangeScene : public Scene {
public:
    bool init() override;

    CREATE_FUNC(StringChangeScene);

private:
    void stringToChar();

    void charToString();

    void charArrayToString();

    void stringToCharArray();

private:

};


#endif //PROJ_ANDROID_STRINGCHANGESCENE_H
