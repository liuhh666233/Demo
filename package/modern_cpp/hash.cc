#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <dbg.h>

int main()
{
    std::vector<int> a{1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
    dbg(a);
    std::sort(a.begin(), a.end());
    dbg(a);
    std::sort(a.begin(), a.end(), std::greater<int>());
    dbg(a);
    auto hp = std::hash<int *>();
    dbg(hp(nullptr));
    dbg(hp(a.data()));
    dbg(static_cast<void *>(a.data()));
    dbg(a.data());
    auto hs = std::hash<std::string>();
    dbg(hs("hello"));
    dbg(hs("hellp"));
}