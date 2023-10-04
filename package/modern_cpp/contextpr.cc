#include <array>
#include <dbg.h>

constexpr int sqr(int n)
{
    return n * n;
}

int main()
{
    constexpr int n = sqr(3);
    int a[n] = {};
    dbg(a[0]);
    dbg(size_t(a));
    std::array<int, sqr(3)> b{1, 1, 1};
    dbg(b[0]);
    return 0;
}