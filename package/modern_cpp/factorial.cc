#include <dbg.h>
#include <functional>
template <int n>
struct factorial
{
    static const int value = factorial<n - 1>::value * n;
};

template <>
struct factorial<0>
{
    static const int value = 1;
};

constexpr int factorial_constexpr(int n)
{
    if (n < 0)
    {
        throw std::invalid_argument(
            "Arg must be non-negative");
    }
    if (n > 0)
    {
        return factorial_constexpr(n - 1) * n;
    }
    return 1;
};

int main()
{
    int a = factorial<11>::value;
    printf("%d\n", factorial<11>::value);
    dbg(a);
    constexpr int b = factorial_constexpr(11);
    dbg(b);

    std::function<int(int)> factorial_lambda = [&](int n) -> int
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return n * factorial_lambda(n - 1);
        }
    };
    dbg(factorial_lambda(10));

    auto factorial_test = [](int n)
    {
        auto _f = [](auto f, int n) -> int
        { if (n == 0) return 1; else return n * f(f,n - 1); };
        return _f(_f, n);
    };
    dbg(factorial_test(10));
    return 0;
}
