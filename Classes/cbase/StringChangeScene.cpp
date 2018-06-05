//
// Created by bovink on 2018/6/5.
//

#include "StringChangeScene.h"

bool StringChangeScene::init() {
    if (!Scene::init()) {
        return false;
    }
    stringToChar();
    return true;
}

void StringChangeScene::stringToChar() {

    CCLOG("%s", "stringToChar");
}

void StringChangeScene::charToString() {

}
