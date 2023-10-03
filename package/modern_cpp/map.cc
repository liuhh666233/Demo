#include <functional>
#include <map>
#include <set>
#include <string>
#include <dbg.h>
using namespace std;

int main()
{
    map<string, int> amap;
    amap.insert({"One", 1});
    amap.insert({"Two", 2});
    amap.insert({"Three", 3});
    amap.insert({"Four", 4});
    dbg(amap);
    multiset<int, greater<int>> mset{1, 2, 3, 1, 1, 2, 3};
    dbg(mset);
    dbg(amap.find("Four") == amap.end());
    dbg(mset.find(1) == mset.end());
    dbg(amap.lower_bound("Four")->second);
    dbg(--amap.lower_bound("Four")->second);

    return 0;
}