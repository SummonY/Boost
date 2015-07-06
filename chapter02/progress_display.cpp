#include <iostream>
#include <fstream>
#include <vector>
#include <boost/progress.hpp>

using namespace std;
using namespace boost;

int main()
{
    vector<string> v(100, "aaa");

    ofstream fs("test.txt");
    
    progress_display pd(v.size());
    vector<string>::iterator pos;
    for (pos = v.begin(); pos != v.end(); ++pos)
    {
        fs << *pos << endl;
        ++pd;
    }
    return 0;
}
