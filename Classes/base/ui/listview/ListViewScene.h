//
// Created by 吴宗刚 on 2018/6/14.
//

#ifndef PROJ_ANDROID_LISTVIEWSCENE_H
#define PROJ_ANDROID_LISTVIEWSCENE_H


#include "cocos2d.h"

USING_NS_CC;

class ListViewScene : public Scene {
public:
    bool init() override;

    CREATE_FUNC(ListViewScene)

    void onButtonClicked(Ref *ref);

};


#endif //PROJ_ANDROID_LISTVIEWSCENE_H
