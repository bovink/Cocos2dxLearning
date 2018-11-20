//
// Created by bovink on 2018/6/5.
//

#include "TestNetworkScene.h"

bool TestNetworkScene::init() {
    if (!Scene::init()) {
        return false;
    }
    auto stencil = DrawNode::create();
    stencil->drawSolidCircle(_contentSize / 2, 50, 360, 10000, Color4F::BLACK);

    auto clipNode = ClippingNode::create();
    clipNode->setStencil(stencil);

    imageView = Sprite::create("HelloWorld.png");
    imageView->setPosition(_contentSize / 2);
    clipNode->addChild(imageView);
    addChild(clipNode);

    auto moveBy = MoveBy::create(5, Vec2(-50, 0));
    imageView->runAction(RepeatForever::create(Sequence::create(moveBy, moveBy->reverse(), nullptr)));

    auto button = Button::create("animationbuttonnormal.png", "animationbuttonpressed.png");
    button->setPosition(Size(_contentSize.width / 2, 100));
    button->addClickEventListener([&](Ref *ref) {

        goHttp->send();
    });
    addChild(button);

    goHttp = new GoHttp();

    goHttp->create()
            ->setUrl(
                    "http://img2.imgtn.bdimg.com/it/u=782046930,1105099424&fm=27&gp=0.jpg")
            ->setRequestType(HttpRequest::Type::GET)
            ->setTag("Test Something");

    goHttp->setFunction([&](vector<char> *buffer) {

        Image *image = new Image();
        image->initWithImageData((unsigned char *) buffer->data(), buffer->size());
        auto texture2D = new Texture2D();
        if (texture2D->initWithImage(image)) {

            imageView->setContentSize(texture2D->getContentSize());
            imageView->setTexture(texture2D);
        }


    });
//    testNetworkGet();

    return true;
}

void TestNetworkScene::testNetworkGet() {

    HttpRequest *request = new(std::nothrow) HttpRequest();
    // required fields
    request->setUrl("http://yunduo.tiilii.com/yunduo/systemIni/getServerTimeValue.do");
    request->setRequestType(HttpRequest::Type::GET);
    request->setResponseCallback(CC_CALLBACK_2(TestNetworkScene::onHttpRequestCompleted, this));

    request->setTag("GET test2");
    HttpClient::getInstance()->send(request);
    // don't forget to release it, pair to new
    request->release();
}

void TestNetworkScene::onHttpRequestCompleted(HttpClient *sender, HttpResponse *response) {
    if (!response) {
        return;
    }

    // You can get original request type from: response->request->reqType
    if (0 != strlen(response->getHttpRequest()->getTag())) {
        log("%s completed", response->getHttpRequest()->getTag());
    }

    long statusCode = response->getResponseCode();
    char statusString[64] = {};
    sprintf(statusString, "HTTP Status Code: %ld, tag = %s", statusCode,
            response->getHttpRequest()->getTag());
    CCLOG("%s", statusString);
    log("response code: %ld", statusCode);

    if (!response->isSucceed()) {
        log("response failed");
        log("error buffer: %s", response->getErrorBuffer());
        return;
    }

    // dump data
    std::vector<char> *buffer = response->getResponseData();
    std::string responseString;
    for (int i = 0; i < buffer->size(); ++i) {
        responseString += (*buffer)[i];
    }
    responseString += "\0";
    CCLOG("response:%s", responseString.c_str());

    log("Http Test, dump data: ");
    for (unsigned int i = 0; i < buffer->size(); i++) {
        log("%c", (*buffer)[i]);
    }
    log("\n");
    if (response->getHttpRequest()->getReferenceCount() != 2) {
        log("request ref count not 2, is %d", response->getHttpRequest()->getReferenceCount());
    }
}
