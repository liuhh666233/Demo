#include <vector>
#include <dbg.h>
class Obj1
{
public:
    Obj1()
    {
        dbg("Obj1()");
    };
    Obj1(const Obj1 &)
    {
        dbg("Obj1(const Obj1&)");
    };
    Obj1(Obj1 &&)
    {
        dbg("Obj1(Obj1&&)");
    }
};

class Obj2
{
public:
    Obj2()
    {
        dbg("Obj2()");
    }
    Obj2(const Obj2 &)
    {
        dbg("Obj2(const Obj2 &)");
    }
    Obj2(Obj2 &&) noexcept
    {
        dbg("Obj2(Obj2 &&)");
    }
};

int main()
{
    using namespace std;
    vector<Obj1> o1;
    o1.reserve(2);
    o1.emplace_back();
    o1.emplace_back();
    o1.emplace_back();
    vector<Obj2> o2;
    o2.reserve(2);
    o2.emplace_back();
    o2.emplace_back();
    o2.emplace_back();
}