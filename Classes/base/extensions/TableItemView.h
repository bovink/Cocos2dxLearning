//
// Created by 吴宗刚 on 2018/7/21.
//

#ifndef PROJ_ANDROID_TABLEITEMVIEW_H
#define PROJ_ANDROID_TABLEITEMVIEW_H

#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocos/ui/CocosGUI.h"

USING_NS_CC;
using namespace extension;
using namespace ui;
using namespace std;

class TableItemView : public TableViewCell {

public:

    bool init() override;

    static TableItemView *newInstance(int index);

    void update(int index);


private:

    int _index;
};


#endif //PROJ_ANDROID_TABLEITEMVIEW_H
