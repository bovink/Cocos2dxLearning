//
// Created by 吴宗刚 on 2018/6/12.
//

#include "LoginView.h"

LoginView::LoginView() {}

LoginView::~LoginView() {}

LoginView *LoginView::newInstance(Presenter *presenter) {
    LoginView *loginView = new LoginView();
    loginView->presenter = presenter;

    return loginView;
}

bool LoginView::init() {
    if (!Scene::init()) {

        return false;
    }

    presenter->bindView(this);

    return true;
}
