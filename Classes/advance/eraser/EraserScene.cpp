//
// Created by 吴宗刚 on 2018/6/13.
//

#include "EraserScene.h"
#include "cocos/ui/CocosGUI.h"

using namespace ui;

bool EraserScene::init() {
    if (!Scene::init()) {

        return false;
    }

    float _contentSizeWidth = getContentSize().width;
    float _contentSizeHeight = getContentSize().height;

    // 添加背景图片
    auto image = Sprite::create("HelloWorld.png");
    image->setPosition(Vec2(_contentSizeWidth / 2, _contentSizeHeight / 2));
    this->addChild(image);
    BlendFunc blend;
    blend = {GL_ONE, GL_ONE_MINUS_SRC_ALPHA};
    image->setBlendFunc(blend);

    // 画布
    auto _canvas = RenderTexture::create(static_cast<int>(_contentSizeWidth),
                                         static_cast<int>(_contentSizeHeight),
                                         Texture2D::PixelFormat::RGBA8888);
    _canvas->retain();
    _canvas->setPosition(Vec2(_contentSizeWidth / 2, _contentSizeHeight / 2));
    this->addChild(_canvas);

    auto _brush = Sprite::create("snow.png");
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

    listener->onTouchMoved = [](Touch *touch, Event *event) {

        auto startPos = touch->getLocation();

        _brush->setPosition(startPos);
        BlendFunc func0 = {GL_ZERO, GL_ONE_MINUS_SRC_ALPHA};
        _brush->setBlendFunc(func0);
        _canvas->begin();
        _brush->visit();
        _canvas->end();
    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}