#include <iostream>
#include <vector>
#include <cmath>
#include <boost/optional.hpp>

using namespace std;
using namespace boost;

optional<double> calc(int x)
{
    return optional<double>(x != 0, 1.0 / x);
}

optional<double> sqrt_op(double x)
{
    return optional<double>(x > 0, sqrt(x));
}


int main()
{
    optional<int> op0;
    optional<int> op1(none);
    assert(!op0);
    assert(op0 == op1);
    assert(op1.get_value_or(253) == 253);
    
    optional<string> ops("test");
    cout << *ops << endl;

    vector<int> v(10);
    optional<vector<int>& > opv(v);
    assert(opv);

    opv->push_back(5);
    assert(opv->size() == 11);

    opv = none;
    assert(!opv);

    optional<double> opd = calc(10);
    if (opd)
    {
        cout << *opd << endl;
    }
    opd = sqrt_op(-10);
    if (!opd)
    {
        cout << "no result" << endl;
    }
    return 0;
}
