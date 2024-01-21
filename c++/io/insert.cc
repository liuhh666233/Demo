#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = v.begin();
    string tmp;
    while (it != v.end())
    {
        if (*it % 2)
        {

            it = v.insert(it, *it);
            ++it;
        }
        for (auto i : v)
            cout << i << " ";
        cout << endl;
        cin >> tmp;
        ++it;
    }

    return 0;
}