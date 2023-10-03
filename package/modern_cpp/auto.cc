#include <iterator>
#include <dbg.h>
#include <vector>
using namespace std;

template <typename T>
void foo(const T &c)
{
    using std::begin;
    using std::end;
    dbg(c);
    for (auto it = begin(c), ite = end(c); it != ite; ++it)
    {
        dbg(*it);
    }
}
int main()
{
    vector<int> v1{1, 2, 3, 4, 5};
    foo(v1);
    auto &&r1 = v1;
    dbg(r1);
    auto &v2 = v1;
    auto &&r2 = v2;
    dbg(r2);
    auto &&r3 = std::move(v1);
    dbg(r3);
    auto &&r4 = r1;
    dbg(r4);
    return 0;
}
