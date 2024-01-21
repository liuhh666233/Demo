#include <iostream>
#include <stdexcept>
using namespace std;

istream &f(istream &in)
{
    int v;
    while (in >> v, !in.eof())
    {
        if (in.bad())
        {
            throw runtime_error("IO stream corrupted");
        }
        if (in.fail())
        {
            cerr << "bad data, try again" << endl;
            in.clear();
            in.ignore(10, ' ');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main()
{
    cout << "Please input some integers: " << endl;
    f(cin);
    return 0;
}