//
// Created by 吴宗刚 on 2018/8/21.
//

#ifndef PROJ_ANDROID_TOAST_H
#define PROJ_ANDROID_TOAST_H

#include "cocos2d.h"
#include "cocos/ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;
using namespace std;

class Toast : public Layout {

public:

    CREATE_FUNC(Toast)

    static Toast *newInstance(string message);

    bool init() override;

private:

    string _message;
    DrawNode *drawNode;
    Text *text;


    void initViews();
};


#endif //PROJ_ANDROID_TOAST_H
