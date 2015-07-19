#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <boost/assign.hpp>

using namespace std;
using namespace boost;

int main()
{
    using namespace boost::assign;

    vector<int> v;
    v += 1, 2, 3, 4, 5, 6 * 6;
    cout << v[0] << endl;

    set<string> s;
    s += "cpp", "java", "c#", "Python";

    map<int, string> m;
    m += make_pair(1, "one"), make_pair(2, "two");
    cout << m[1] << endl;
    return 0;
}
