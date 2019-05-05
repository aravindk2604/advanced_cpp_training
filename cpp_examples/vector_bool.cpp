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

	vector(initializer_list<Value> il) // : s{il.size()}, data{ new Value[s] }
	  : vector(il.size())
	{
	    std::copy(begin(il), end(il), data);
	}

	      Value& operator[](size_t i)       { check(i); return data[i]; }
	const Value& operator[](size_t i) const { check(i); return data[i]; }

	size_t size() const { return s; }
      private:
	size_t s;
	Value* data;
    };

    class vb_proxy
    {
      public:
	using uchar= unsigned char;
	
	vb_proxy(uchar& byte, size_t pos)
	  : byte{byte}, mask{static_cast<uchar>(1 << pos)} {}

	vb_proxy& operator=(bool value)
	{
	    if (value)
		byte|= mask;
	    else
		byte&= ~mask;
	    return *this;
	}

	operator bool() const { return byte & mask; }

      private:
	uchar& byte;
	uchar  mask;
    };

    template <>
    class vector<bool>
    {
	using uchar= unsigned char;
      public:
	vector(size_t s) : s{s}, data{ new uchar[(s+7)/8] } {}

	vector(initializer_list<bool> il) : vector(il.size())
	{
	    size_t i{0};
	    for (bool value : il)
		(*this)[i++]= value;
	}

	bool operator[](size_t i) const { return data[i/8] >> i%8 & 1; }

	vb_proxy operator[](size_t i) { return {data[i/8], i%8};   }

	size_t size() const { return s; }
      private:
	size_t s;
	uchar* data;
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

    vector<bool> v(3);
    v[0]= true; v[1]= true; v[2]= false;

    cout << "v[1] = " << boolalpha << v[1] << endl;
    assert(v[1]);

    cout << "v = " << v << endl;

    vector<bool> w{true, false, true};
    cout << "w = " << w << endl;
    assert(!w[1]);

    
    return 0;
}
  
 
