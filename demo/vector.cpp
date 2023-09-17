#include <iostream>
#include <vector>
#include <numeric>
auto add(int a, int b)
{
    return a + b;
}

int main()
{
    int myInt = 5;
    auto myAutoInt = 5;
    std::cout << myInt << std::endl;
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    for (auto const &it : myVector)
    {
        std::cout << it << std::endl;
    }
    // Calculate the sum of the vector
    int sum = 0;
    for (auto const &it : myVector)
    {
        sum = add(sum, it);
    }
    std::cout << sum << std::endl;

    std::partial_sum(myVector.begin(), myVector.end(), myVector.begin());
    for (auto const &it : myVector)
    {
        std::cout << it << std::endl;
    }
}