#include <thread>
#include <future>
#include <dbg.h>
using namespace std;

template <typename F, typename... Ts>
inline auto reallyAsync(F &&f, Ts &&...params)
{
    return async(std::launch::async, std::forward<F>(f), std::forward<Ts>(params)...);
}

int main()
{
    auto f = reallyAsync([]
                         { 
                            // Print the thread id
                            dbg(this_thread::get_id());
                            return 7; });
    dbg("Main thread id: ", this_thread::get_id());
    dbg(f.get());
}