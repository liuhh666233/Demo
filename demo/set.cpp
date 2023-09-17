#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec;
    for (int i = 0; i != 10; ++i)
    {
        ivec.push_back(i);
        ivec.push_back(i);
    }
    set<int> iset(ivec.cbegin(), ivec.cend());
    set<int> iset2;
    iset2.insert(ivec.cbegin(), ivec.cend());
    iset2.insert({1, 3, 5, 7, 9});
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    cout << ivec.size() << endl;
    cout << iset.size() << endl;
    cout << miset.size() << endl;
}
