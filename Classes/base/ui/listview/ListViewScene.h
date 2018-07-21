//
// Created by 吴宗刚 on 2018/6/14.
//

#ifndef PROJ_ANDROID_LISTVIEWSCENE_H
#define PROJ_ANDROID_LISTVIEWSCENE_H


#include "BaseScene.h"


class ListViewScene : public BaseScene {
public:
    bool init() override;

    CREATE_FUNC(ListViewScene)

    void onButtonClicked(Ref *ref);

private:
    ui::Button *generateButton();
};


#endif //PROJ_ANDROID_LISTVIEWSCENE_H
