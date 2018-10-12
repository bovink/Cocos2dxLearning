//
// Created by 吴宗刚 on 2018/6/13.
//

#include "ButtonScene.h"
#include "cocos/ui/CocosGUI.h"

using namespace ui;

bool ButtonScene::init() {

    if (!Scene::init()) {
        return false;
    }
    float _contentSizeWidth = getContentSize().width;
    float _contentSizeHeight = getContentSize().height;

    auto content = Layout::create();
    content->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
    content->setBackGroundColor(Color3B::WHITE);
    content->setContentSize(_contentSize);
    addChild(content);

    auto button = Button::create("ps_jsu_anniu7.png", "ps_jsu_anniu7.png");
    button->setPosition(Vec2(_contentSizeWidth / 2, _contentSizeHeight / 2));

    // 点击事件
    button->addClickEventListener([](Ref *ref) {

        CCLOG("click button");
    });

    // 触摸事件
    button->addTouchEventListener([](Ref *ref, Widget::TouchEventType type) {
        Button *clickButton;
        clickButton = dynamic_cast<Button *>(ref);
        switch (type) {
            case Widget::TouchEventType::BEGAN:
                clickButton->setOpacity(50);
                CCLOG("touch begin");
                break;
            case Widget::TouchEventType::MOVED:
                CCLOG("touch moved");
                break;
            case Widget::TouchEventType::ENDED:
                clickButton->setOpacity(255);
                CCLOG("touch ended");
                break;
            case Widget::TouchEventType::CANCELED:
                clickButton->setOpacity(255);
                CCLOG("touch canceled");
                break;
        }
    });

    addChild(button);

    return true;
}

bool TestClipScene::init() {
    if (!BaseScene::init()) {
        return false;
    }

    auto renderer = _director->getRenderer();
    auto &parentTransform = _director->getMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);

    auto sprite = ImageView::create("ps_danci_k1.png");
    sprite->setPosition(_contentSize / 2);

    auto cutSprite = ImageView::create("testbg.png");
    cutSprite->setScale9Enabled(true);
    cutSprite->setContentSize(_contentSize);
    cutSprite->setPosition(_contentSize / 2);

    auto _texture = RenderTexture::create(_contentSize.width,
                                          _contentSize.height,
                                          Texture2D::PixelFormat::RGBA8888);
    _texture->retain();
    _texture->setPosition(_contentSize / 2);
    addChild(_texture);

    _texture->begin();
    cutSprite->visit(renderer, parentTransform, true);
    _texture->end();

    BlendFunc func0 = {GL_ZERO, GL_ONE_MINUS_SRC_ALPHA};
    sprite->setBlendFunc(func0);

    _texture->begin();
    sprite->visit(renderer, parentTransform, true);
    _texture->end();


    return true;
}

void TestClipScene::setColor4B(int x, int y, int width, Color4B color, unsigned char *data) {

}

bool TestClipScene::expectColor4B(int x, int y, int width, Color4B color, unsigned char *data) {
    return false;
}
