#include <dbg.h>
#include <map>
#include <functional>
using namespace std;

template <typename T>
auto test1(T fn)
{
    dbg(fn);
    return (*fn)(2);
}

template <typename T>
auto test2(T &fn)
{
    dbg(fn);
    return fn(2);
}

template <typename T>
auto test3(T *fn)
{
    dbg(fn);
    return (*fn)(2);
}

int add_2(int x)
{
    return x + 2;
};

int main()
{
    auto fn = [](int x)
    { return x + 2; };
    dbg(test1(add_2));
    dbg(test2(add_2));
    dbg(test3(&add_2));

    map<string, function<int(int, int)>>
        op_dict{
            {"+",
             [](int x, int y)
             {
                 return x + y;
             }},
            {"-",
             [](int x, int y)
             {
                 return x - y;
             }},
            {"*",
             [](int x, int y)
             {
                 return x * y;
             }},
            {"/",
             [](int x, int y)
             {
                 return x / y;
             }},
        };
    // dbg(op_dict["+"]);
    dbg(op_dict["+"](2, 2));
    return 0;
}