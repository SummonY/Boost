#include <iostream>
#include <vector>
#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace std;
using namespace boost;

class shared
{
    private:
        shared_ptr<int> p;
    public:
        shared(shared_ptr<int> p_):p(p_){}
        void print()
        {
            cout << "p() count : " << p.use_count() << " v = " << *p << endl;
        }
};

void print_func(shared_ptr<int> p)
{
    cout << "pf() count : " << p.use_count() << " v = " << *p << endl;
}

int main()
{
    shared_ptr<int> p (new int(100));
    shared s1(p), s2(p);

    s1.print();
    s2.print();

    *p = 20;
    print_func(p);

    s1.print();
    s2.print();

    shared_ptr<string> sp = make_shared<string>("make_shared");
    shared_ptr<vector<int> > spv = make_shared<vector<int> >(10, 2);
    cout << "sp = " << *sp << " size = " << sp->size() << endl;
    cout << "size = " << spv->size() << endl;
    assert(spv->size() == 10);

    typedef vector<shared_ptr<int> > vs;
    vs v(10);

    int i = 0;
    for (vs::iterator pos = v.begin(); pos != v.end(); ++pos)
    {
        (*pos) = make_shared<int>(++i);
        cout << *(*pos) << ", ";
    }
    cout << endl;
    shared_ptr<int> p5 = v[9];
    *p5 = 100;
    cout << *v[9] << endl;
}
