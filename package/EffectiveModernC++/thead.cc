#include <thread>
#include <future>
#include <vector>
constexpr int tenMillion = 10'000'000;

class ThreadRAII
{
public:
    enum class DtorAction
    {
        join,
        detach
    };
    ThreadRAII(std::thread &&t, DtorAction a) : action(a), t(std::move(t)) {}
    ~ThreadRAII()
    {
        if (t.joinable())
        {
            if (action == DtorAction::join)
            {
                t.join();
            }
            else
            {
                t.detach();
            }
        }
    }
    std::thread &get() { return t; }

private:
    DtorAction action;
    std::thread t;
};

bool conditionsAreSatisfied() { return true; }

void processVals(const std::vector<int> &vals)
{
    for (auto i : vals)
    {
        // do something
    }
}

bool doWork(
    std::function<bool(int)> filter, int maxVal = tenMillion)
{
    std::vector<int> goodVals;
    ThreadRAII t(
        std::thread([&filter, maxVal, &goodVals]
                    {
            for (auto i=0;i<=maxVal;++i){
                if (filter(i)) goodVals.push_back(i);
            } }),
        ThreadRAII::DtorAction::join);
    auto nh = t.get().native_handle();
    if (conditionsAreSatisfied())
    {
        t.get().join();
        processVals(goodVals);
        return true;
    }
    return false;
}

int main()
{
    doWork([](int i)
           { return i % 2 == 0; });
}