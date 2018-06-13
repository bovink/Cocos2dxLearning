//
// Created by 吴宗刚 on 2018/6/13.
//

#include "EraserScene.h"

bool EraserScene::init() {
    if (!Scene::init()) {

        return false;
    }

    float _contentSizeWidth = getContentSize().width;
    float _contentSizeHeight = getContentSize().height;

    // 添加背景图片
    auto image = Sprite::create("animationbuttonnormal.png");
    image->setPosition(Vec2(_contentSizeWidth / 2, _contentSizeHeight / 2));
    this->addChild(image);

    // 画布
    _canvas = RenderTexture::create(static_cast<int>(_contentSizeWidth),
                                    static_cast<int>(_contentSizeHeight),
                                    Texture2D::PixelFormat::RGBA8888);
    _canvas->retain();
    _canvas->setPosition(Vec2(_contentSizeWidth / 2, _contentSizeHeight / 2));
    this->addChild(_canvas);

    _brush = Sprite::create("snow.png");
    _brush->setScale(3.5);
    _brush->retain();

    auto mask = Sprite::create("HelloWorld.png");
    mask->setPosition(Vec2(_contentSizeWidth / 2, _contentSizeHeight / 2));

    _canvas->begin();
    mask->visit();
    _canvas->end();


    addTouchEventListener();
    return true;
}

void EraserScene::addTouchEventListener() {

    auto listener = EventListenerTouchOneByOne::create();

    listener->onTouchBegan = [](Touch *touch, Event *event) {

        return true;
    };

    listener->onTouchMoved = CC_CALLBACK_2(EraserScene::onTouchMoved, this);

    listener->onTouchEnded = [](Touch *touch, Event *event) {

    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void EraserScene::onTouchMoved(Touch *touch, Event *event) {

    auto startPos = touch->getLocation();

    _brush->setPosition(startPos);
    BlendFunc func0 = {GL_ZERO, GL_ONE_MINUS_SRC_ALPHA};
    _brush->setBlendFunc(func0);
    _canvas->begin();
    _brush->visit();
    _canvas->end();
}