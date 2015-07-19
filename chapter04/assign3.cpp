#include <iostream>
#include <set>
#include <boost/assign.hpp>

using namespace std;
using namespace boost;

int main()
{
    using namespace boost::assign;

    vector<int> v = list_of(1) (2) (3) (4) (5);
    cout << v[0] << endl;

    deque<string> d = (list_of("power") ("bomb"), "phazon", "suit");
    cout << d[0] << endl;

    set<int> s = (list_of(10), 20, 30, 40, 50);
    for (set<int>::const_iterator p = s.cbegin(); p != s.cend(); ++p)
    {
        cout << *p << " ";
    }
    cout << endl;

    map<int ,string> m = list_of(make_pair(1, "one")) (make_pair(2, "two"));
    cout << m[2] << endl;
    return 0;
}
