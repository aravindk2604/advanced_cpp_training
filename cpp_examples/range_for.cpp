#include <iostream>

using namespace std;

namespace ct {

    class iiter
    {
      public:
	iiter(int i) : i{i} {}

	bool operator!=(iiter that) const { return i != that.i; }
	iiter& operator++() { ++i; return *this; }
	int operator*() const { return i; }

	iiter operator++(int) {
	    iiter tmp{*this};
	    i++;
	    return tmp;
	}
	
      private:
	int i;
    };
    
    class irange
    {
      public:
	explicit irange(int from, int to)
	  : from{from}, to{to} {}

	iiter begin() const { return iiter{from}; }
	iiter end() const { return iiter{to}; }

      private:
	int from, to;
    };
    
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    for (int i : irange{1, 11})
	cout << i << endl;

    irange r{11, 21};
    for (iiter it= r.begin(); it != end(r); it++) {
	int i= *it;
	cout << i << endl;
    }
    
#if 0
    A[3][6];
    sub_matrix(A, 3, 8, 11, 15);
    A[irange{3, 8}][irange{11, 15}];
    irange rr{3, 8}, cr{11, 15};
    A[rr][cr];
#endif

    return 0;
}
  
 
