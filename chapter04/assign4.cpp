#include <iostream>
#include <boost/assign.hpp>

using namespace std;

int main()
{
    using namespace boost::assign;

    vector<int> v = list_of(1).repeat(3, 2) (3) (4) (5);
    cout << v[0] << endl;

    multiset<int> ms;
    insert(ms).repeat_fun(5, &rand).repeat(2, 1), 10;

    deque<int> d;
    push_front(d).range(v.begin(), v.begin() + 5);
    cout << d[0] << endl;

    return 0;
}
