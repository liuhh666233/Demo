#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    auto even_numbers = numbers | std::views::filter([](int n)
                                                     { return n % 2 == 0; });

    for (int n : even_numbers)
    {
        std::cout << n << ' ';
    }
}