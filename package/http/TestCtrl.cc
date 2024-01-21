#include "TestCtrl.h"

void TestCtrl::asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto resp = HttpResponse::newHttpResponse();
    resp->setStatusCode(k200OK);
    // resp->setBody("<p>Hello, world!</p>");
    resp->setContentTypeCode(CT_TEXT_HTML);
    resp->setBody("Hello, world!");
    // resp->setExpiredTime(0);
    callback(resp);
}