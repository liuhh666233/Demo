#include <vector>
#include <iterator>
#include <algorithm>
#include <dbg.h>
#include <iostream>
using namespace std;
int main()
{
    vector<int> v1{1, 2, 3, 4};
    vector<int> v2;
    copy(
        v1.begin(), v1.end(), back_inserter(v2));
    dbg(v2);
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, "  "));
    return 0;
}