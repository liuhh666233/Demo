#include <iostream>
#include <stdexcept>

int divide(int a, int b)
{
    if (b == 0)
    {
        throw std::runtime_error("Divide by zero!");
    }
    return a / b;
}

int main()
{
    int num1, num10;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num10;
    try
    {
        std::cout << divide(num1, num10) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}