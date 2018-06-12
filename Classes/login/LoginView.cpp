//
// Created by 吴宗刚 on 2018/6/12.
//

#include "LoginView.h"

LoginView::LoginView() {}

LoginView::~LoginView() {}

LoginView *LoginView::newInstance(Presenter *presenter) {
    LoginView *loginView = new LoginView();
    loginView->presenter = presenter;

    if (loginView->init()) {
        loginView->autorelease();
        return loginView;
    } else {

        delete loginView;
        return nullptr;
    }

}

bool LoginView::init() {
    if (!Scene::init()) {

        return false;
    }

    presenter->bindView(this);

    CCLOG("init");
    CCLOG("%s", presenter->getUserName().c_str());

    return true;
}
