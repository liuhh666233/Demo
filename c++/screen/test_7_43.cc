#include <string>
#include <iostream>

using namespace std;

class NoDefault
{
public:
    NoDefault(int i) { val = i; };
    int val;
};
class C
{
public:
    NoDefault nd;
    C(int i = 0) : nd(i){};
};

int main()
{
    C c(1);
    cout << c.nd.val << endl;
    return 0;
}