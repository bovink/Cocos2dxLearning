//
// Created by bovink on 2018/6/5.
//

#include "StringChangeScene.h"

bool StringChangeScene::init() {
    if (!Scene::init()) {
        return false;
    }
    stringToChar();
    charToString();
    stringToCharArray();
    charArrayToString();
    return true;
}

void StringChangeScene::stringToChar() {

    CCLOG("stringToChar");

    std::string s = "this is a string";
    char c = s[0];

    CCLOG("char:%c", c);
}

void StringChangeScene::charToString() {

    CCLOG("charToString");

    char c = 'c';

    std::string s;
    s[0] = c;
//    s += c;

    CCLOG("string:%s", s.c_str());
}

void StringChangeScene::stringToCharArray() {

    CCLOG("stringToCharArray");

    std::string s = "this is a string";
    char c[s.size()];
    for (int i = 0; i < s.size(); ++i) {
        c[i] = s[i];
    }
    for (int i = 0; i < s.size(); ++i) {
        CCLOG("char:%c", c[i]);
    }

}

void StringChangeScene::charArrayToString() {

    CCLOG("charArrayToString");

    char c[] = "this is a string";
    std::string s;
    s = c;
    CCLOG("string:%s",s.c_str());


}
