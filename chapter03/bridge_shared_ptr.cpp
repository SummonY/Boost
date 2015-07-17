#include <iostream>
#include <boost/make_shared.hpp>

using namespace std;
using namespace boost;

class sample
{
    private:
        class impl;
        shared_ptr<impl> p;
    public:
        sample();
        void print();
};

// 内部类
class sample::impl
{
    public:
        void print()
        {
            cout << "impl print" << endl;
        }
};


sample::sample():p(new impl)
{
    
}

void sample::print()
{
    p->print();
}


int main()
{
    sample s;
    s.print();
    return 0;
}
