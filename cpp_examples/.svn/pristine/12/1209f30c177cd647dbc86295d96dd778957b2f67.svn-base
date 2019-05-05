#include <iostream>

using namespace std;

namespace ct {

    template <typename T>
    T maxi(T x, T y)
    { 
	return x > y ? x : y;
    }

    template int maxi(int, int);

    inline long maxi(long x, long y)
    { 
	return x > y ? x : y;
    }

    namespace {
	
	short maxi(short x, short y)
	{ 
	    return x > y ? x : y;
	}	
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    cout << "maxi(3, 7) = " << maxi(3, 7) << endl;
    cout << "maxi(3l, 7l) = " << maxi(3l, 7) << endl;
    cout << "maxi<long>(3l, 7l) = " << maxi<long>(3l, 7) << endl;
    cout << "maxi(3.1, 7.2) = " << maxi(3.1, 7.2) << endl;

    // cout << "maxi(3, 7.2) = " << maxi(3, 7.2) << endl;

    cout << "maxi(3, 7.2) = " << maxi((double)3, 7.2) << endl; // don't use
    cout << "maxi(3, 7.2) = " << maxi(double(3), 7.2) << endl; // not much better
    cout << "maxi(3, 7.2) = " << maxi(static_cast<double>(3), 7.2) << endl;

    cout << "maxi<long double>(3, 7.2) = " << maxi<long double>(3, 7.2) << endl;

    short s1{4}, s2{5};
    cout << "maxi(s1, s2) = " << maxi(s1, s2) << endl;
}
  
 
