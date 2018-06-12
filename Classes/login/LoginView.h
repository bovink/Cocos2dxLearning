//
// Created by 吴宗刚 on 2018/6/12.
//

#ifndef PROJ_ANDROID_LOGINVIEW_H
#define PROJ_ANDROID_LOGINVIEW_H

#include "cocos2d.h"
#include "LoginContract.h"

USING_NS_CC;

class LoginView : public Scene, public View {

public:
    LoginView();

    ~LoginView();

    static LoginView *newInstance(Presenter *presenter);

    bool init() override;

private:

    Presenter *presenter;
};


#endif //PROJ_ANDROID_LOGINVIEW_H
