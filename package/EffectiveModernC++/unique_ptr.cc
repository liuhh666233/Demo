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

class Bond : public Investment
{
public:
    Bond()
    {
        dbg("Bond constructor");
    }
    ~Bond()
    {
        dbg("Bond destructor");
    }
};

class RealEstate : public Investment
{
public:
    RealEstate()
    {
        dbg("RealEstate constructor");
    }
    ~RealEstate()
    {
        dbg("RealEstate destructor");
    }
};

template <typename... Ts>
auto makeInvestment(Ts &&...params)
{
    auto delInvmt = [](Investment *pInvestment)
    {
        dbg("custom deleter called");
        delete pInvestment;
    };
    std::unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt);
    if (true)
    {
        pInv.reset(new Stock(std::forward<Ts>(params)...));
    }
    else if (false)
    {
        pInv.reset(new Bond(std::forward<Ts>(params)...));
    }
    else
    {
        pInv.reset(new RealEstate(std::forward<Ts>(params)...));
    }
}

int main()
{
    makeInvestment();
    return 0;
}
