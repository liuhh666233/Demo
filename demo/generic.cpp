#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <iterator>
using namespace std;

int main()
{
    istream_iterator<int> in(cin), eof;
    vector<int> vec(in, eof);
    ostream_iterator<int> out(cout, " ");
    for (auto r_iter = vec.crbegin(); r_iter != vec.crend(); ++r_iter)
        *out++ = *r_iter;
}