#include <dbg.h>
#include <vector>
#include <iostream>
struct magic_number
{
    /* data */
    static const int number = 42;
    static constexpr int c = 42;
    static constexpr const int &d = c;
};

int main()
{
    std::vector<int> a;
    a.push_back(magic_number::number);
    std::cout << a[0] << std::endl;
    dbg(magic_number::c);
    dbg(magic_number::d);
    // dbg(a);
    return 0;
}   