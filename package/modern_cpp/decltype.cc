#include <iterator>
#include <dbg.h>
#include <vector>
#include <array>
#include <string>
#include <map>
using namespace std;
template <typename T>
struct MyObj
{
    MyObj(T value) : value_(value){};
    T value_;
};
MyObj(const char *) -> MyObj<string>;

int main()
{
    int v1{10};
    dbg(v1);
    decltype(v1) v2;
    dbg(v2);
    decltype((v1)) v3 = v1;
    dbg(v3);
    decltype(v1 + v2) v4;
    dbg(v4);
    decltype(auto) v5 = v1;
    dbg(v5);
    decltype(auto) v6 = v3;
    dbg(v6);
    decltype(auto) v7 = std::move(v1);
    dbg(v7);
    pair<int, int> pr1{1, 42};
    dbg(pr1);
    auto pr2 = make_pair(1, 42);
    dbg(pr2);
    pair pr3{1, 42};
    dbg(pr3);
    int a1[] = {1, 2, 3};
    dbg(a1);
    array<int, 3> a2{1, 2, 3};
    dbg(a2);
    // C17
    array a3{1, 2, 3};
    dbg(a3);

    MyObj obj("hello");
    dbg(obj.value_);
    map<string, int> mmp;
    mmp.insert({"four", 1});
    auto m1 = mmp["four"];
    dbg(m1);
    return 0;
}
