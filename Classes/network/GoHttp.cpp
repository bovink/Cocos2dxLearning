//
// Created by 吴宗刚 on 2018/7/19.
//

#include "GoHttp.h"

GoHttp *GoHttp::create() {
    if (_hr == nullptr) {

        _hr = new(std::nothrow) HttpRequest();
        _hr->setResponseCallback(CC_CALLBACK_2(GoHttp::onHttpRequestCompleted, this));
    }
    return this;
}

GoHttp *GoHttp::setUrl(const std::string &url) {
    _hr->setUrl(url);
    return this;
}

GoHttp *GoHttp::setRequestType(HttpRequest::Type type) {
    _hr->setRequestType(type);
    return this;
}

GoHttp *GoHttp::setResponseCallback() {

    return this;
}

GoHttp *GoHttp::setTag(const std::string &tag) {
    _hr->setTag(tag);
    return this;
}

void GoHttp::onHttpRequestCompleted(HttpClient *sender, HttpResponse *response) {

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
        // 失败
        return;
    }

    // 打印数据
    std::vector<char> *buffer = response->getResponseData();
    if (_function) {

        _function(buffer);
    }

    std::string responseString;
    for (int i = 0; i < buffer->size(); ++i) {
        responseString += (*buffer)[i];
    }
    responseString += "\0";
    CCLOG("response:%s", responseString.c_str());

}

void GoHttp::send() {
    HttpClient::getInstance()->send(_hr);
    // don't forget to release it, pair to new
    _hr->release();
}

void GoHttp::setFunction(GoHttp::DataFunction function) {

    _function = function;
}
