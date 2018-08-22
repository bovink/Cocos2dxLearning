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
    image = Sprite::create("animationbuttonnormal.png");
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

    mask = Sprite::create("HelloWorld.png");
    mask->retain();
    mask->setPosition(Vec2(_contentSizeWidth / 2, _contentSizeHeight / 2));

    _canvas->begin();
    mask->visit();
    _canvas->end();


    addTouchEventListener();
    num = 0;
    return true;
}

void EraserScene::addTouchEventListener() {

    auto listener = EventListenerTouchOneByOne::create();

    listener->onTouchBegan = CC_CALLBACK_2(EraserScene::onTouchBegan, this);

    listener->onTouchMoved = CC_CALLBACK_2(EraserScene::onTouchMoved, this);

    listener->onTouchEnded = [](Touch *touch, Event *event) {

    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool EraserScene::onTouchBegan(Touch *touch, Event *event) {

    CCLOG("%d", num);
    num++;
    if (num % 3 == 2) {

        image->setTexture("button.png");

        _canvas->begin();
        mask->visit();
        _canvas->end();
    }
    return true;
}

void EraserScene::onTouchMoved(Touch *touch, Event *event) {

    auto startPos = touch->getLocation();

    if (num % 3 == 1) {

        _canvas->clear(0, 0, 0, 0);
    }
    _brush->setPosition(startPos);
    BlendFunc func0 = {GL_ZERO, GL_ONE_MINUS_SRC_ALPHA};
    _brush->setBlendFunc(func0);
    _canvas->begin();
    _brush->visit();
    _canvas->end();
}

bool EraserScene2::init() {
    if (!Scene::init()) {
        return false;
    }
    initView();
    return true;
}

void EraserScene2::initView() {

    auto content = Layout::create();
    content->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
    content->setBackGroundColor(Color3B::WHITE);
    content->setContentSize(_contentSize);
    addChild(content);

    std::string filename = "ps_danci_k1.png";

    // 背景
    auto s = Sprite::create(filename);
    s->setPosition(_contentSize / 2);
    addChild(s);

    img = new Image();
    img->initWithImageFile(filename);

    CCLOG("%s loaded. Size: %dx%d. Bits per pixel: %d", filename.c_str(), img->getWidth(),
          img->getHeight(), img->getBitPerPixel());

    data = img->getData(); //pixel data
    width = img->getWidth();

    for (int height = 0; height < img->getHeight(); ++height) {
        for (int width = 0; width < img->getWidth(); ++width) {

            Color4B alpha = Color4B(0, 0, 0, 0);
            if (!expectColor4B(width, height, img->getWidth(), alpha, data)) {

                setColor4B(width, height, img->getWidth(), Color4B::GRAY, data);
            }
        }
    }

    Texture2D *texture = new Texture2D();
    texture->initWithImage(img);

    // 遮罩
    sprite = Sprite::createWithTexture(texture);
    sprite->setPosition(_contentSize / 2);
    addChild(sprite);

    addTouchEventListener();

    LatticePoint::getFromCircle(30, list);
}

void EraserScene2::setColor4B(int x, int y, int width, Color4B color, unsigned char *data) {

    int index = (x + y * width) << 2; //the same as * 4
    data[index] = color.r;
    data[index + 1] = color.g;
    data[index + 2] = color.b;
    data[index + 3] = color.a;
}

bool EraserScene2::expectColor4B(int x, int y, int width, Color4B color, unsigned char *data) {

    int index = (x + y * width) << 2; //the same as * 4

    return data[index] == color.r &&
           data[index + 1] == color.g &&
           data[index + 2] == color.b &&
           data[index + 3] == color.a;
}

void EraserScene2::addTouchEventListener() {

    auto listener = EventListenerTouchOneByOne::create();

    listener->onTouchBegan = CC_CALLBACK_2(EraserScene2::onTouchBegan, this);

    listener->onTouchMoved = CC_CALLBACK_2(EraserScene2::onTouchMoved, this);

    listener->onTouchEnded = [](Touch *touch, Event *event) {

    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void EraserScene2::onTouchMoved(Touch *touch, Event *event) {

    Vec2 pos = touch->getLocation();
    Color4B alpha = Color4B(0, 0, 0, 0);
    if (sprite->getBoundingBox().containsPoint(pos)) {

        Vec2 pos1 = sprite->convertToNodeSpace(pos);
        Vec2 pos2 = sprite->convertToNodeSpaceAR(pos);
        CCLOG("pos1:%f,%f", pos1.x, pos1.y);
        CCLOG("pos2:%f,%f", pos2.x, pos2.y);
//        for (int i = pos1.x - 10; i < pos1.x + 10; ++i) {
//            for (int j = pos1.y - 10; j < pos1.y + 10; ++j) {
//
//                setColor4B(i, img->getHeight() - j, img->getWidth(), alpha, data);
//            }
//
//        }

//        Vec2 center = Vec2(img->getWidth() / 2, img->getHeight() / 2);
        for (int i = 0; i < list.size(); ++i) {
            int x = static_cast<int>(list.at(i).x + pos1.x);
            int y = static_cast<int>(list.at(i).y + img->getHeight() - pos1.y);
            if (x < 0 || x > img->getWidth()) {

                continue;
            }

            setColor4B(x, y, img->getWidth(), alpha, data);
        }
        Texture2D *texture = new Texture2D();
        texture->initWithImage(img);
        sprite->setTexture(texture);
    }
}

bool EraserScene2::onTouchBegan(Touch *touch, Event *event) {
    return true;
}

