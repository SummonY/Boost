#include <iostream>
#include <boost/make_shared.hpp>

using namespace std;
using namespace boost;

class abstract
{
    public:
        virtual void f() = 0;
        virtual void g() = 0;
    protected:
        virtual ~abstract(){}
};

class impl : public abstract
{
    public:
        virtual void f()
        {
            cout << "class impl f" << endl;
        }
        virtual void g()
        {
            cout << "class impl g" << endl;
        }
};

shared_ptr<abstract> create()
{
    return shared_ptr<abstract>(new impl);
}

int main()
{
    shared_ptr<abstract> p = create();
    p->f();
    p->g();

    return 0;
}
