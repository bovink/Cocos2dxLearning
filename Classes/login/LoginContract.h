//
// Created by 吴宗刚 on 2018/6/12.
//

#ifndef PROJ_ANDROID_LOGINCONTRACT_H
#define PROJ_ANDROID_LOGINCONTRACT_H


#include "BasePresenter.h"
#include <string>

class LoginContract {

};

class View : public BaseView {

};

class Presenter : public BasePresenter<View> {

public:
    virtual std::string getUserName() = 0;
};


#endif //PROJ_ANDROID_LOGINCONTRACT_H
