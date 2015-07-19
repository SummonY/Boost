#include <iostream>
#include <boost/typeof/typeof.hpp>
#include <boost/optional.hpp>

using namespace std;
using namespace boost;

int main()
{
    BOOST_AUTO(x, make_optional(5));
    cout << *x << endl;
    assert(*x == 5);

    BOOST_AUTO(y, make_optional<double>((*x > 10), 1.0));
    cout << y << endl;
    assert(!y);
    return 0;
}
