#include <thread>
#include <future>
#include <dbg.h>
#include <chrono>
#include <mutex>

std::promise<void> p;

void react()
{
    dbg("Reacting task", std::this_thread::get_id());
}

void detect()
{
    std::thread t(
        []
        {
            dbg("Waiting for promise");
            p.get_future().wait();
            dbg("Detecting task", std::this_thread::get_id());
            react();
        });
    dbg("Setting promise");
    // Sleep for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(5));
    p.set_value();
    t.join();
}
int main()
{
    detect();
    return 0;
}