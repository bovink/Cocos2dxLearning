//
// Created by 吴宗刚 on 2018/6/13.
//

#ifndef PROJ_ANDROID_CUSTOMVIEWCELL_H
#define PROJ_ANDROID_CUSTOMVIEWCELL_H

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CustomViewCell : public TableViewCell {
public:
    void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;

    bool init() override;

    CustomViewCell(ssize_t _id);

    void updateCell(ssize_t id);

private:
    ssize_t _id;
};


#endif //PROJ_ANDROID_CUSTOMVIEWCELL_H
