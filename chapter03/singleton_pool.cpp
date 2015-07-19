#include <iostream>
#include <boost/pool/singleton_pool.hpp>

using namespace std;
using namespace boost;

struct pool_tag{};

typedef singleton_pool<pool_tag, sizeof(int)> spl;

int main()
{
    int *p = (int *)spl::malloc();
    assert(spl::is_from(p));
    spl::release_memory();

    return 0;
}
