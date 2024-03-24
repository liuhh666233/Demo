#include <thread>
#include <future>
#include <dbg.h>
#include <chrono>
#include <mutex>
int main()
{
    std::condition_variable cv;
    std::mutex m;
    auto detecting_task = std::async(std::launch::async, [&cv]
                                     { 
                            // Print the thread id
                            dbg("Detecting task", std::this_thread::get_id());
                            // Sleep for 1 second
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            // Notify the main thread
                            cv.notify_one();
                            return 7; });
    auto reacting_task = std::async(std::launch::async, [&cv, &m]
                                    {
                            std::unique_lock<std::mutex> lk(m);
                            cv.wait(lk);
                            // Print the thread id
                            dbg("Reacting task", std::this_thread::get_id());
                            // Sleep for 1 second
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            return 8; });
    dbg("Main thread id: ", std::this_thread::get_id());
    dbg(reacting_task.get());
}