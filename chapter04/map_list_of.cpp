#include <iostream>
#include <map>
#include <boost/assign.hpp>

using namespace std;
using namespace boost;

int main()
{
    using namespace boost::assign;

    map<int, int> m1 = map_list_of(1, 2) (3, 4) (5, 6);
    cout << m1[1] << endl;

    map<int, string> m2 = map_list_of(1, "one") (2, "two");
    cout << m2[1] << endl;
    return 0;
}
