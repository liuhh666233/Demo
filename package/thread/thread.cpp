#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono;
using namespace std;
using ull = unsigned long long;
ull OddSum = 0;
ull EvenSum = 0;

void FindEven(ull start, ull end)
{
    for (ull i = start; i <= end; ++i)
    {
        if ((i & 1) == 0)
        {
            EvenSum += i;
        }
    }
}
void FindOdd(ull start, ull end)
{
    for (ull i = start; i <= end; ++i)
    {
        if ((i & 1) == 1)
        {
            OddSum += i;
        }
    }
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
    cout << "OddSum = " << OddSum << endl;
    cout << "EvenSum = " << EvenSum << endl;
    cout << "Time taken by function: "
         << duration.count() / 1000 << " microseconds" << endl;
    return 0;
}