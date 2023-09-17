#include <iostream>

void modifyVariable(int *ptr)
{
    *ptr = 20;
}

int main()
{
    int a = 10;
    const int *p = &a;
    int *q = const_cast<int *>(p);
    std::cout << *p << std::endl;
    modifyVariable(q);
    std::cout << *q << std::endl;
}