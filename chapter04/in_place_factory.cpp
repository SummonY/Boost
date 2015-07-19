#include <iostream>
#include <vector>
#include <boost/optional.hpp>

using namespace std;
using namespace boost;

int main()
{
    optional<string> ops(in_place("test in_place_factory"));
    cout << *ops << endl;

    optional<vector<int> > opp(in_place(10, 3));
    cout << opp->size() << endl;
    cout << (*opp)[0] << endl;

    assert(opp->size() == 10);
    assert((*opp)[0] == 3);
    return 0;
}
