#include <functional>
#include <vector>
#include <memory>
#include <queue>
#include <dbg.h>
using namespace std;
int main()
{
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;
    pq.push({1, 1});
    pq.push({2, 2});
    pq.push({0, 3});
    pq.push({9, 4});
    dbg(pq);
    while (!pq.empty())
    {
        dbg(pq.top());
        pq.pop();
    }

    return 0;
}