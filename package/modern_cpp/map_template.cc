#include <vector>
#include <dbg.h>
#include <functional>
#include <type_traits>
#include <numeric>

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

template <typename F>
auto compose(F f)
{
    return [f](auto &&...x)
    {
        return f(std::forward<decltype(x)>(x)...);
    };
}
template <typename F, typename... Args>
auto compose(F f, Args... other)
{
    return [f, other...](auto &&...x)
    {
        return f(compose(other...)(std::forward<decltype(x)>(x)...));
    };
}

int main()
{
    vector<int> a{1, 2, 3, 4, 5};
    auto add_one = [](int x)
    { return x + 1; };
    dbg(fmap(add_one, a));
    auto square_list =
        [](auto &&container)
    {
        return fmap(
            [](int x)
            { return x * x; },
            container);
    };
    auto sum_list =
        [](auto &&container)
    {
        return accumulate(
            container.begin(),
            container.end(), 0);
    };
    dbg(a);
    auto squared_sum =
        compose(sum_list, square_list);
    dbg(squared_sum(a));
    return 0;
}
