#include <iostream>
#include <boost/type_index.hpp>
#include <typeinfo>
using namespace std;
using boost::typeindex::type_id;

class shape
{
public:
    virtual ~shape() {}
};

class circle : public shape
{
#define CHECK_TYPEID(object, type)                                 \
    cout << "typeid(" #object << ")"                               \
         << (typeid(object) == typeid(type) ? " is " : " is NOT ") \
         << #type << endl
#define CHECK_TYPE_ID(object, type)                                                \
    cout << "type_id(" #object << ")"                                              \
         << (type_id<decltype(object)>() == type_id<type>() ? " is " : " is NOT ") \
         << #type << endl
};

int main()
{
    shape *s = new circle();
    CHECK_TYPEID(*s, shape);
    CHECK_TYPEID(*s, circle);
    CHECK_TYPE_ID(*s, shape);
    CHECK_TYPE_ID(*s, circle);
    delete s;
    return 0;
}
