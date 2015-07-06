#include <iostream>

#define BOOST_DATE_TIME_SOURCE
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

int main()
{
    date d1(2000, 1, 1), d2(2008, 8, 8);

    cout << d2 - d1 << endl;
    assert(d1 + (d2 - d1) == d2);

    d1 += days(10);
    assert(d1.day() == 11);
    cout << d1.day() << endl;

    d1 += months(2);
    assert(d1.month() == 3 && d1.day() == 11);
    cout << d1.month() << endl;

    d1 -= weeks(1);
    assert(d1.day() == 4);
    cout << d1.day() << endl;

    d2 -= years(7);
    assert(d2.year() == d1.year() + 1);
    cout << d2.year() << endl;

    date d(2008, 11, 20);
    date d_start(d.year(), d.month(), 1);
    date d_end = d.end_of_month();

    for (day_iterator d_iter(d_start); d_iter != d_end; ++d_iter)
    {
        cout << *d_iter << " " << d_iter->day_of_week() << endl;
    }

    return 0;
}
