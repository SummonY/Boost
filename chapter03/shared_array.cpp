#include <iostream>
#include <boost/smart_ptr.hpp>

using namespace std;
using namespace boost;

int main()
{
    int *p = new int[100];
    shared_array<int> sa(p);
    shared_array<int> sa2 = sa;

    sa[0] = 10;
    cout << sa2[0] << endl;
    assert(sa2[0] == 10);
    return 0;
}
