//
// Created by 吴宗刚 on 2018/6/12.
//

#ifndef PROJ_ANDROID_LOGINPRESENTER_H
#define PROJ_ANDROID_LOGINPRESENTER_H

#include "LoginContract.h"

class LoginPresenter : public Presenter {

public :
    LoginPresenter();

    ~LoginPresenter();

    void bindView(View *baseView) override;

private:
    View *view;
};


#endif //PROJ_ANDROID_LOGINPRESENTER_H
