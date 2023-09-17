#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1, 4, 2, 3, 4, 4, 5, 4};
    v.erase(std::remove(v.begin(), v.end(), 4), v.end());
    for (auto i : v)
        std::cout << i << " ";
}