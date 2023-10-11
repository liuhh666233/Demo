#include <thread>
#include <dbg.h>
#include <chrono>
#include <utility>
#include <atomic>

using namespace std;
std::atomic_int x = 0;
// int x = 0;
std::atomic_int y = 0;

void func1()
{

    x = 1;
    y.store(2, memory_order_release);
}
void func2()
{
    if (y.load(memory_order_acquire) == 2)
    {
        x = 3;
        y.store(4, memory_order_relaxed);
    }
}
void func()
{
    int i = 0;
    while (i < 100)
    {
        ++i;
        ++x;
        --x;
    }
    dbg(x);
}
int main()
{
    std::thread thread1{func};
    std::thread thread2{func};
    std::thread thread3{func};
    std::thread thread4{func};
    std::thread thread11{func};
    std::thread thread21{func};
    std::thread thread31{func};
    std::thread thread41{func};
    std::thread thread112{func};
    std::thread thread212{func};
    std::thread thread312{func};
    std::thread thread412{func};
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread11.join();
    thread21.join();
    thread31.join();
    thread41.join();
    thread112.join();
    thread212.join();
    thread312.join();
    thread412.join();
    dbg(x);
    return 0;
}