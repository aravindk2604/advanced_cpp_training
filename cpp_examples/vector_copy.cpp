#include <iostream>
#include <cassert>
#include <initializer_list>
#include <algorithm>

using namespace std;

namespace ct {

    template <typename Value>
    class vector
    {
	void check(size_t i) const { assert(i < s); }

	void copy_that(const vector& that) {
	    std::copy(that.data, that.data + s, data);
	}
      public:
	explicit vector(size_t s) : s{s}, data{ new Value[s] } {}

	vector(initializer_list<double> il) 
	  : vector(il.size())
	{
	    std::copy(begin(il), end(il), data);
	}

	vector(const vector& that) : vector(that.size())
	{
	    copy_that(that);
	}

	vector& operator=(const vector& that) &
	{
	    assert(s == that.s);
	    copy_that(that);
	    return *this;
	}
	
	~vector() { delete[] data; }

	      Value& operator[](size_t i) &      { check(i); return data[i]; }
	const Value& operator[](size_t i) const& { check(i); return data[i]; }

	size_t size() const { return s; }
      private:
	size_t s;
	Value* data;
    };
    
    template <typename Value>
    std::ostream& operator<<(std::ostream& os, const vector<Value>& v)
    {
	os << "{";
	if (v.size() > 0)
	    os << v[0];
	for (size_t i= 1; i < v.size(); ++i)
	    os << ", " << v[i];
	return os << "}";
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    vector<double> v{4.8, 3.8, 9.1};
    cout << "v = " << v << endl;
    assert(abs(v[1] - 3.8) < 1e-12);

    vector<double> w{v};
    cout << "w = " << w << endl;

    v[0]= 666;
    w[1]= 999;
    cout << "v = " << v << endl;
    cout << "w = " << w << endl;

    vector<double> x(w.size());
    x= w;
    cout << "x = " << x << endl;
    
    
    return 0;
}
  
 
