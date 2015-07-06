#include <iostream>
#include <boost/progress.hpp>
#include <boost/static_assert.hpp>

template<int N = 2>
class new_progress_timer : public boost::timer
{
    public:
        new_progress_timer(std::ostream &os = std::cout) : m_os(os)
        {
            BOOST_STATIC_ASSERT(N >= 0 && N <= 10);
        }
        ~new_progress_timer(void)
        {
            try
            {
                std::istream::fmtflags old_flags = m_os.setf(std::istream::fixed, std::istream::floatfield);
                std::streamsize old_prec = m_os.precision(N);

                // print time
                m_os << elapsed() << " s(new progress timer)"
                    << std::endl;

                // retrieve stream
                m_os.flags(old_flags);
                m_os.precision(old_prec);
            }
            catch (...)
            {
                
            }
        }
    private:
        std::ostream &m_os;
};

using namespace std;
using namespace boost;

int main()
{
    progress_timer t;

    cout << "time1 : " << t.elapsed() << "s" << endl;

    new_progress_timer<10> nt;
    cout << "time2 : " << nt.elapsed();

    return 0;
}
