//
// Created by 吴宗刚 on 2018/6/13.
//

#ifndef PROJ_ANDROID_ERASERSCENE_H
#define PROJ_ANDROID_ERASERSCENE_H

#include "BaseScene.h"


class EraserScene : public Scene {

public:
    CREATE_FUNC(EraserScene)

    bool init() override;

    void addTouchEventListener();

    void onTouchMoved(Touch *touch, Event *event);

    bool onTouchBegan(Touch *touch, Event *event);

    RenderTexture *_canvas;
    Sprite *_brush;
    Sprite *mask;
    Sprite *image;
    int num;
};


class EraserScene2 : public BaseScene {

public:

    CREATE_FUNC(EraserScene2)

    bool init() override;

private:
    void initView();

    void setColor4B(int x, int y, int width, Color4B color, unsigned char *data);

    void addTouchEventListener();

    void onTouchMoved(Touch *touch, Event *event);

    bool onTouchBegan(Touch *touch, Event *event);

    Image *img;
    unsigned char *data;
    int width;
    Sprite *sprite;
};

#endif //PROJ_ANDROID_ERASERSCENE_H
