#include <iostream>
#include <utility>
#include <dbg.h>
class Obj
{
public:
    Obj()
    {
        dbg("Obj()");
    }
    Obj(Obj &)
    {
        dbg("Obj(&)");
    }
    Obj(Obj &&)
    {
        dbg("Obj(&&)");
    }
};

Obj simple()
{
    Obj a;
    return a;
};

Obj simple_with_move()
{
    Obj a;
    return std::move(a);
}

Obj complicated(int n)
{
    Obj a;
    Obj b;
    if (n % 2 == 2)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    dbg("1 **************");
    Obj obj1 = simple();

    dbg("2 **************");
    Obj obj2 = simple_with_move();

    dbg("3 **************");
    Obj obj3 = complicated(2);
    return 0;
}