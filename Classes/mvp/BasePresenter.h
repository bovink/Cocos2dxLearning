//
// Created by 吴宗刚 on 2018/6/12.
//

#ifndef PROJ_ANDROID_BASEPRESENTER_H
#define PROJ_ANDROID_BASEPRESENTER_H


#include "BaseView.h"

template<class T>
class BasePresenter {

public:
    virtual void bindView(T *baseView) = 0;
};


#endif //PROJ_ANDROID_BASEPRESENTER_H
