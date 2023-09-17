#include <iostream>
#include <memory>

using namespace std;
int main()
{
    unique_ptr<int> p1(new int(42));
    unique_ptr<int> p2 = make_unique<int>(42);
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    unique_ptr<int> p3 = std::move(p1);
    if (p1)
    {
        /* code */
        cout << "*p1 = " << *p1 << endl;
    }
    else
    {
        cout << "p1 is nullptr" << endl;
        cout << "*p3 = " << *p3 << endl;
    }

    return 0;
}