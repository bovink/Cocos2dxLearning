//
// Created by bovink on 2018/6/4.
//

#ifndef PROJ_ANDROID_CUSTOMTABLECELLVIEW_H
#define PROJ_ANDROID_CUSTOMTABLECELLVIEW_H

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CustomTableCellView : public TableViewCell {

public:
    virtual bool init() override;

    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;

    CustomTableCellView(ssize_t id);

    void updateCell(ssize_t id);

public:
    ssize_t id;
    Vector<Sprite*> vector;
};


#endif //PROJ_ANDROID_CUSTOMTABLECELLVIEW_H
