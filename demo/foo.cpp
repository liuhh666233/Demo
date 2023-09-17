#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;

private:
    vector<int> data;
};

Foo Foo::sorted() &&
{
    cout << "Foo Foo::sorted() &&" << endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const &
{
    cout << "Foo Foo::sorted() const &" << endl;
    return Foo(*this).sorted();
}

int main()
{
    Foo f;
    f.sorted();

    return 0;
}
