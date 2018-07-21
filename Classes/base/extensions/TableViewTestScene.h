//
// Created by 吴宗刚 on 2018/7/21.
//

#ifndef PROJ_ANDROID_TABLEVIEWTESTSCENE_H
#define PROJ_ANDROID_TABLEVIEWTESTSCENE_H

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
using namespace extension;

class TableViewTestScene : Scene, TableViewDataSource, TableViewDelegate {

public:

    bool init() override;
};


#endif //PROJ_ANDROID_TABLEVIEWTESTSCENE_H
