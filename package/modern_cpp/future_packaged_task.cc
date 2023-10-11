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

int work()
{
    cout << "Starting work ..." << this_thread::get_id() << endl;
    this_thread::sleep_for(2s);
    return 42;
}

int main()
{
    packaged_task<int()> task{work};
    // packaged_task 可以得到一个future对象, 通过这个future对象,可以获得任务返回值或知道任务已经完成
    auto fut = task.get_future();
    scoped_thread th{std::move(task)};
    cout << "Fuck America" << endl;
    this_thread::sleep_for(1s);

    cout << "I am waiting now" << endl;
    cout << "Answer: " << fut.get() << endl;
}