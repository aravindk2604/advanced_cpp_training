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
      public:
	explicit vector(size_t s) : s{s}, data{ new Value[s] } {}

	vector(initializer_list<double> il) // : s{il.size()}, data{ new Value[s] }
	  : vector(il.size())
	{
	    std::copy(begin(il), end(il), data);
	}

	      Value& operator[](size_t i)       { check(i); return data[i]; }
	const Value& operator[](size_t i) const { check(i); return data[i]; }

	// template <typename VValue>
	// friend std::ostream& operator<<(std::ostream& os, vector<VValue>& v);

	size_t size() const { return s; }
      private:
	size_t s;
	Value* data;
    };
    
    template <typename Value>
    std::ostream& operator<<(std::ostream& os, const vector<Value>& v)
    {
	// v[0]= 666;
	os << "{";
	if (v.size() > 0)
	    os << v[0];
	for (size_t i= 1; i < v.size(); ++i)
	    os << ", " << v[i];
	return os << "}";
    }

    size_t array_size(const vector<double>& v)
    {
	return v.size();
    }    
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    // vector<double> v{3};
    vector<double> v(3);
    v[0]= 4.2; v[1]= 5.3; v[2]= 6.7;

    cout << "v[1] = " << v[1] << endl;
    assert(abs(v[1] - 5.3) < 1e-12);

    cout << "v = " << v << endl;
    // v << (cout << "v = ") << endl; // as method

    vector<double> w{4.8, 3.8, 9.1};
    cout << "w = " << w << endl;
    assert(abs(w[1] - 3.8) < 1e-12);

    cout << "w has " << array_size(w) << " entries.\n";
    // cout << "7 has " << array_size(7) << " entries.\n";
    // ccout << "7 has " << array_size(static_cast<vector<double>>(7)) << " entries.\n";

    // vector<double> z= 8;
    cout << "temp vector has " << array_size(vector<double>{4, 2, 9, 9, 1, 44}) << " entries.\n";
    
    return 0;
}
  
 
