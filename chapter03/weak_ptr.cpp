#include <iostream>
#include <boost/smart_ptr.hpp>

using namespace std;
using namespace boost;

int main()
{
    shared_ptr<int> sp(new int(10));
    cout << sp.use_count() << endl;

    weak_ptr<int> wp(sp);
    cout << wp.use_count() << endl;

    if (!wp.expired())
    {
        shared_ptr<int> sp2 = wp.lock();
        *sp2 = 100;
        cout << wp.use_count() << endl;
    }

    cout << wp.use_count() << endl;
    sp.reset();
    assert(wp.expired());
    assert(!wp.lock());
    return 0;
}
