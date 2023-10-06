#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

// 整数、字符串、字符串的三元组
using num_tuple =
    tuple<int, string, string>;

ostream &
operator<<(ostream &os,
           const num_tuple &value)
{
    os << get<0>(value) << ','
       << get<1>(value) << ','
       << get<2>(value);
    return os;
}

int main()
{
    // 阿拉伯数字、英文、法文
    vector<num_tuple> vn{
        {1, "one", "un"},
        {2, "two", "deux"},
        {3, "three", "trois"},
        {4, "four", "quatre"}};
    // 修改第 0 项的法文
    get<2>(vn[0]) = "une";
    // 按法文进行排序
    sort(vn.begin(), vn.end(),
         [](auto &&x, auto &&y)
         {
             return get<2>(x) <
                    get<2>(y);
         });
    // 输出内容
    for (auto &&value : vn)
    {
        cout << value << endl;
    }
    // 输出多元组项数
    constexpr auto size =
        tuple_size_v<num_tuple>;
    cout << "Tuple size is " << size << endl;
}