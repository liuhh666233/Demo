#include <vector>
#include <dbg.h>
#include <functional>
#include <type_traits>
#include <numeric>

template <class T, T... Ints>
struct integer_sequence
{
};

template <class T>
struct integer_sequence_ns
{
    template <T N, T... Ints>
    struct integer_sequence_helper
    {
        using type = typename integer_sequence_helper<N - 1, N - 1, Ints...>::type;
    };
    template <T... Ints>
    struct integer_sequence_helper<0, Ints...>
    {
        using type = typename integer_sequence<T, Ints...>::type;
    };
};
template <class T, T N>
using make_integer_sequence = typename integer_sequence_ns<T>::template integer_sequence_helper<N>::type;

template <class T, T... Ints>
struct integer_sequence
{
};

template <class T, T N, T... Is>
auto make_integer_sequence_impl()
{
    if constexpr (N == 0)
    {
        return integer_sequence<
            T, Is...>();
    }
    else
    {
        return make_integer_sequence_impl<
            T, N - 1, N - 1, Is...>();
    }
}

template <class T, T N>
using make_integer_sequence =
    decltype(make_integer_sequence_impl<
             T, N>());