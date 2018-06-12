//
// Created by 吴宗刚 on 2018/6/12.
//

#include "LoginView.h"


LoginView *LoginView::newInstance(Presenter *presenter) {
    LoginView *loginView = new LoginView();
    loginView->presenter = presenter;

    return loginView;
}

bool LoginView::init() {
    if (!Layer::init()) {

        return false;
    }

    presenter->bindView(this);

    return true;
}
