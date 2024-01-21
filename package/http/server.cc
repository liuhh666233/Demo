#include <drogon/drogon.h>
#include <memory>
using namespace drogon;

int main()
{
    app().setLogPath("./").setLogLevel(trantor::Logger::kWarn).addListener("0.0.0.0", 5000).setThreadNum(16).run();
};