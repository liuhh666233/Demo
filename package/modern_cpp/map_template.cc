#include <vector>
#include <dbg.h>
using namespace std;
template <
    template <typename, typename> class OutContainer = vector,
    class F, class R>
auto fmap(F &&f, R &&inputs)
{
    typedef decay_t<decltype(f(*inputs.begin()))> result_type;
    OutContainer<result_type, allocator<result_type>> result;
    for (auto &&item : inputs)
    {
        result.push_back(f(item));
    }
    return result;
};

int main()
{
    vector<int> a{1, 2, 3, 4, 5};
    auto add_one = [](int x)
    { return x + 1; };
    dbg(fmap(add_one, a));
    return 0;
}
