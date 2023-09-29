//
// Created by light on 20-1-31.
//

// 1.函数指针
#include <thread>
#include <iostream>
#include <dbg.h>
using namespace std;

void fun(int id, int x)
{
    while (x-- > 0)
    {
        cout << id << " -- " << x << endl;
    }
};

int main()
{
    dbg(fun);
    std::thread t1(fun, 1, 10);
    std::thread t2(fun, 2, 10);
    t1.join();
    t2.join();
    return 0;
}