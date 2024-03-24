#include "dbg.h"
#include <memory>

class Investment
{
public:
    Investment()
    {
        dbg("Investment constructor");
    }
    virtual ~Investment()
    {
        dbg("Investment destructor");
    }
};

class Stock : public Investment
{
public:
    Stock()
    {
        dbg("Stock constructor");
    }
    ~Stock()
    {
        dbg("Stock destructor");
    }
};

std::vector<std::shared_ptr<Widget>> processedWidgets;

auto logginDel = [](Investment *pInvestment)
{
    dbg("loggingDel: custom deleter");
    delete pInvestment;
};

class Widget : public std::enable_shared_from_this<Widget>
{
public:
    void process()
    {
        dbg("processing Widget");
        processedWidgets.emplace_back(shared_from_this());
    }
};

int main()
{
    std::shared_ptr<Investment> pInv(new Stock, logginDel);
}