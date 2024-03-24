#include "dbg.h"
#include <vector>

struct IntVecWrap
{
    std::vector<int> data;

    template <typename... P>
    explicit IntVecWrap(P &&...v);
};

template <typename... P>
IntVecWrap::IntVecWrap(P &&...v) : data{std::forward<P>(v)...}
{
    dbg(data);
}

int main()
{
    IntVecWrap v1(6, 5);
    IntVecWrap v2{6, 5};
}