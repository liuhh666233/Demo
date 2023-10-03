#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <dbg.h>
int main()
{
    std::list<int> alist{1, 2, 3, 4, 7, 6, 5};
    std::vector<int> avector{1, 2, 3, 4, 8, 7, 6, 5};
    dbg(alist);
    dbg(avector);
    sort(avector.begin(), avector.end());
    alist.sort();
    dbg(alist);
    dbg(avector);
    std::queue<int> aqueue;
    aqueue.push(111);
    aqueue.push(211);
    aqueue.push(311);
    aqueue.push(411);
    aqueue.push(411);
    while (!aqueue.empty())
    {
        dbg(aqueue.front());
        aqueue.pop();
    }
    std::stack<int> astack;
    astack.push(111);
    astack.push(211);
    astack.push(311);
    astack.push(411);
    astack.push(411);
    while (!astack.empty())
    {
        dbg(astack.top());
        astack.pop();
    }
    
    return 0;
}