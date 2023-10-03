#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <dbg.h>

void func(int &x)
{
    dbg("func(int &x)");
    dbg(x);
}

void func(int &&x)
{
    dbg("func(int &&x)");

    dbg(x);
}
template <typename T>
void relay(T &&arg)
{
    func(std::forward<T>(arg));
}

int main()
{
    int x = 1;
    relay(x);
    relay(1);
    relay(12);
    return 0;
}
