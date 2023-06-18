#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int target = 5;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto beg = v.begin(), end = v.end();
    auto mid = beg + (end - beg) / 2;
    while (mid != end && *mid != target)
    {
        if (target < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
    }
     cout << (mid == end ? "not found" : "found") << endl;
}