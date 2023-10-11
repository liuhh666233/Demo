#include <chrono>
#include <future>
#include <iostream>
#include <thread>
#include <utility>

using namespace std;
class scoped_thread
{
public:
    template <typename... Arg>
    scoped_thread(Arg &&...arg) : thread_(std::forward<Arg>(arg)...) {}
    scoped_thread(scoped_thread &&other) : thread_(std::move(other.thread_)) {}
    scoped_thread(const scoped_thread &) = delete;
    ~scoped_thread()
    {
        if (thread_.joinable())
        {
            thread_.join();
        }
    }

private:
    thread thread_;
};

void work(promise<int> prom)
{
    cout << "Starting work ..." << this_thread::get_id() << endl;
    this_thread::sleep_for(2s);
    prom.set_value(42);
}

int main()
{
    promise<int> prom;
    auto fut = prom.get_future();
    // promise 和future 成对出现, 有人负责往prom 中set_value, 有人到时间就可以从future获取到设置的值
    // promise只能设置一次, future也只能设置一次
    scoped_thread th{work, std::move(prom)};
    cout << "I am waiting now" << endl;
    cout << "Answer :" << fut.get() << endl;
}