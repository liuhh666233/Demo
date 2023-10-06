#include <vector>
#include <dbg.h>
#include <functional>
#include <type_traits>
#include <numeric>
using namespace std;
constexpr int
count_bits(unsigned char value)
{
    if (value == 0)
    {
        return 0;
    }
    else
    {
        return (value & 1) +
               count_bits(value >> 1);
    }
}

template <size_t... V>
struct bit_count_t
{
    unsigned char
        // sizeof...(V) 可以求出变长参数V的实际长度, 也就是 255
        count[sizeof...(V)] = {
            // static_cast<unsigned char>(count_bits(V))... 完成了三个操作
            // 依次在每个参数上调用count_bits(arg),在通过static_cast<unsigned char>( ) 将其转换为unsigned char
            static_cast<unsigned char>(
                count_bits(V))...};
};

template <size_t... V>
constexpr bit_count_t<V...>
// index_sequence = integer_sequence<size_t, _Idx...>;
// 因此index_sequence<256, 0, 1 , 2, ..., 255> 中的变长参数V..., 只保留了<0,1,2,...,255>
get_bit_count(index_sequence<V...>)
{
    return bit_count_t<V...>();
}

auto bit_count = get_bit_count(
    // 通过make_index_sequence 产生 index_sequence<256, 0, 1 , 2, ..., 255>
    make_index_sequence<256>());

int main()
{
    int a = static_cast<int>(bit_count.count[10]);
    dbg(a);
    return 0;
}