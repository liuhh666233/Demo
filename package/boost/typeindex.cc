#include <iostream>
#include <boost/type_index.hpp>
#include <typeinfo>
#include <vector>
#include <utility>
using namespace std;
using boost::typeindex::type_id;
using boost::typeindex::type_id_with_cvr;

template <typename T>
void f(T param)
{
    cout << type_id_with_cvr<T>() << endl;
}; // 仍然以传值的方式处理param

int main()
{
    const char *const ptr = // ptr是一个常量指针，指向常量对象
        "Fun with pointers";

    f(ptr); // 传递const char * const类型的实参

    // vector<int> v;
    // auto it = v.begin();
    // cout << "*** Using typeid ***" << endl;
    // // typeid 是标准C++关键字, 可以应用到变量和类型上,返回一个type_info对象
    // cout << typeid(const int).name() << endl;
    // cout << typeid(v).name() << endl;
    // cout << typeid(it).name() << endl;

    // cout << "*** Using type_id ***" << endl;
    // // type_id<T>() 返回一个type_index对象, 该对象包含了类型T的信息
    // cout << type_id<const int>() << endl;
    // cout << type_id<decltype(v)>() << endl;
    // cout << type_id<decltype(it)>() << endl;

    // cout << "*** Using type_id_with_cvr ***" << endl;
    // // type_id_with_cvr<T>() 返回一个type_index对象, 该对象包含了类型T的信息, 但是会保留cvr属性
    // cout << type_id_with_cvr<const int>() << endl;
    // cout << type_id_with_cvr<decltype((v))>() << endl;
    // cout << type_id_with_cvr<decltype(move((v)))>() << endl;
    // cout << type_id_with_cvr<decltype((it))>() << endl;
}