#include <iostream>
#include <boost/assign.hpp>

using namespace std;
using namespace boost;

int main()
{
    using namespace boost::assign;
    vector<int> v;
    push_back(v) (1) (2) (3) (4) (5);
    cout << v[1] << endl;

    list<string> l;
    push_front(l) ("cpp") ("java") ("c#") ("python");

    set<double> s;
    insert(s) (3.14) (0.618) (1.732);

    map<int, string> m;
    insert(m) (1, "one") (2, "two");
    cout << m[1] << endl;
    return 0;
}
