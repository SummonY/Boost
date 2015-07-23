#include <iostream>
#include <queue>
#include <stack>
#include <boost/assign.hpp>

using namespace std;


int main()
{
    using namespace boost::assign;

    stack<int> stk = (list_of(1), 2, 3).to_adapter();
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    queue<string> q = (list_of("china")("us")("uk")).repeat(2, "russia").to_adapter();
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    priority_queue<double> pq = (list_of(1.414), 1.732, 2.236).to_adapter();
    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}
