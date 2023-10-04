#include <vector>   // std::array
#include <iostream> // std::cout/endl
#include <numeric>  // std::accumulate

using namespace std;

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    auto result = accumulate(v.begin(), v.end(), 1, [](int x, int y)
                             { return x * y; });
    std::cout << result << std::endl;
}