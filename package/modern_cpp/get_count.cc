#include <chrono>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <dbg.h>
using namespace std;

int get_count()
{
    static int count = 0;
    return ++count;
}

class task
{
public:
    task(int data) : data_(data) {}
    auto lazy_launch()
    {
        auto count = get_count();
        dbg(count);
        return
            [this, count]() mutable
        {
            ostringstream oss;
            oss << "Done work " << data_
                << " (No. " << count
                << ") in thread "
                << this_thread::get_id()
                << '\n';
            msg_ = oss.str();
            cout << msg_;
            calculate();
        };
    }
    void calculate()
    {
        this_thread::sleep_for(100ms);
        cout << msg_;
    }

private:
    int data_;
    string msg_;
};

int main()
{
    auto t = task{37};
    thread t1{t.lazy_launch()};
    thread t2{t.lazy_launch()};
    t1.join();
    t2.join();
}