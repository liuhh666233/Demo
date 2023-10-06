#include <iostream>
#include <chrono>
#include <thread>
#include <dbg.h>
using namespace std::chrono;
using namespace std;
using ull = unsigned long long;

auto FindEven(ull start, ull end)
{
    ull EvenSum = 0;
    dbg(this_thread::get_id());
    for (ull i = start; i <= end; ++i)
    {
        if ((i & 1) == 0)
        {
            EvenSum += i;
        }
    }
    return EvenSum;
}
auto FindOdd(ull start, ull end)
{
    ull OddSum = 0;
    dbg(this_thread::get_id());
    for (ull i = start; i <= end; ++i)
    {
        if ((i & 1) == 1)
        {
            OddSum += i;
        }
    }
    return OddSum;
}
int main()
{

    ull start = 0, end = 1900000000;

    auto startTime = high_resolution_clock::now();
    std::thread t1(FindEven, start, end);
    std::thread t2(FindOdd, start, end);
    t1.join();
    t2.join();
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    // cout << "OddSum = " << OddSum << endl;
    // cout << "EvenSum = " << EvenSum << endl;
    cout << "Time taken by function: "
         << duration.count() / 1000 << " microseconds" << endl;
    return 0;
}