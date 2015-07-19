#include <iostream>
#include <boost/pool/pool.hpp>

using namespace std;
using namespace boost;

int main()
{
    pool<> pl(sizeof(int));
    int *p = (int *)pl.malloc();
    assert(pl.is_from(p));

    pl.free(p);
    for (int i = 0; i < 100; ++i)
    {
        pl.ordered_malloc(10);
    }
    return 0;
}
