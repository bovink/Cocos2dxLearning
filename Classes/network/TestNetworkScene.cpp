//
// Created by bovink on 2018/6/5.
//

#include "TestNetworkScene.h"

bool TestNetworkScene::init() {
    if (!Scene::init()) {
        return false;
    }

    testNetworkGet();
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
