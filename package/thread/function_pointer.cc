//
// Created by light on 20-1-31.
//

// 1.函数指针
#include <thread>
#include <iostream>

using namespace std;

void fun(int id, int x)
{
    while (x-- > 0)
    {
        cout << id << " -- " << x << endl;
    }
}
// 注意：如果我们创建多线程 并不会保证哪一个先开始
int main()
{
    std::thread t1(fun, 1, 10);
    std::thread t2(fun, 2, 10);
    t1.join();
    t2.join();
    return 0;
}