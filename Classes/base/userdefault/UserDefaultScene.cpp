//
// Created by 吴宗刚 on 2018/7/12.
//

#include "Toast.h"
#include "UserDefaultScene.h"

bool UserDefaultScene::init() {
    if (!BaseScene::init()) {
        return false;
    }

    testSaveData();

    return true;
}

void UserDefaultScene::testSaveData() {

    bool first = UserDefault::getInstance()->getBoolForKey("isFirstIn", false);
    if (first) {

        __CCLOGWITHFUNCTION("非第一次进");
    } else {

        __CCLOGWITHFUNCTION("第一次进");
        UserDefault::getInstance()->setBoolForKey("isFirstIn", true);
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto content = Layout::create();
    content->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
    content->setBackGroundColor(Color3B::WHITE);
    content->setContentSize(_contentSize);
    addChild(content);

    auto s = Sprite::create("animationbuttonnormal.png");
    s->setPosition(_contentSize / 2);

    addChild(s);


    std::string filename = "HelloWorld.png";
    img = new Image();
    img->initWithImageFile(filename);

    CCLOG("%s loaded. Size: %dx%d. Bits per pixel: %d", filename.c_str(), img->getWidth(), img->getHeight(), img->getBitPerPixel());

    data = img->getData(); //pixel data

    memset(data + img->getDataLen() / 4, 255, img->getDataLen() / 4); //white rectangle
    for (int i = 0; i < 195; ++i) {
        for (int j = 0; j < 195; ++j) {

            Color4B a = Color4B(0, 0, 0, 0);
            setColor4B(i, j, a, data); //single red pixel
        }
    }

    texture = new Texture2D();
    texture->initWithImage(img);
    auto sprite = Sprite::createWithTexture(texture);

    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    addChild(sprite);

    setColor4B(85, 109, Color4B::GREEN, data); //single green pixel
    //we have to update texture
//    texture->updateWithData(data, 0, 0, img->getWidth(), img->getHeight()); //here's how to update whole data
    texture->updateWithData(data, 85, 109, 1, 1); //you can also update only part of it to increase performance



}

void UserDefaultScene::setColor4B(int x, int y, Color4B color, unsigned char* data){
    int index = (x + y * img->getWidth()) << 2; //the same as * 4
    data[index] = color.r;
    data[index + 1] = color.g;
    data[index + 2] = color.b;
    data[index + 3] = color.a;
}
