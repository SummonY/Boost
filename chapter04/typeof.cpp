#include <iostream>
#include <vector>
#include <boost/typeof/typeof.hpp>
#include <typeinfo>
#include <boost/make_shared.hpp>
#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

namespace ex
{
    struct demo_class
    {
        int a, b;
    };
}
BOOST_TYPEOF_REGISTER_TYPE(ex::demo_class)

using namespace std;
using namespace boost;

vector<string> func()
{
    vector<string> v(10);
    return v;
}

#define auto_t      BOOST_AUTO


int main()
{
    BOOST_TYPEOF(2.0 * 3) x = 2.0 * 3;
    BOOST_AUTO(y, 2 + 3);

    BOOST_AUTO(a, new double[20]);
    BOOST_AUTO(p, make_pair(1, "string"));
    BOOST_AUTO(v, func());

    BOOST_AUTO(x2, make_pair("test", ex::demo_class()));
    cout << typeid(x2).name() << endl;
    x2.second.a = 10;
    x2.second.b = 20;
    cout << x2.second.a << " " << x2.second.b << endl;

    auto_t(p2, make_shared<int>(1000));
    cout << *p2 << endl;
    return 0;
}
