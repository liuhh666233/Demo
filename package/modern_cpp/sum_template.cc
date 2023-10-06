#include <dbg.h>

template <typename T>
constexpr auto sum(T x)
{
    return x;
}

template <typename T1, typename T2, typename... Args>
auto sum(T1 x, T2 y, Args... args)
{
    return sum(x + y, args...);
}

int main()
{
    sum(1.0, 2, 3, 4, 5, 6);
    return 0;
}