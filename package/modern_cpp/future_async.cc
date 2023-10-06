#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

int work()
{
    this_thread.sleep(2s);
    return 42;
}
int main
{
    auto fut = async(launch::async, work);
    cout << "Fuck" << endl;
    cout << fut.get() << endl;
}