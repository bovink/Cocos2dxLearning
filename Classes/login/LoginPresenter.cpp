//
// Created by 吴宗刚 on 2018/6/12.
//

#include "LoginPresenter.h"

LoginPresenter::LoginPresenter() {}

LoginPresenter::~LoginPresenter() {}

void LoginPresenter::bindView(View *baseView) {

    view = baseView;
}

std::string LoginPresenter::getUserName() {
    std::string name = "lix";

    return name;
}
