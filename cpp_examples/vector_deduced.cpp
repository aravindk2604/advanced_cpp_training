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
	vector() : s{0}, data{nullptr} {}
	
	explicit vector(size_t s) : s{s}, data{ new Value[s] }
	{cout << "size ctor\n";}

	vector(initializer_list<Value> il) 
	  : vector(il.size())
	{
	    cout << "list ctor\n";
	    std::copy(begin(il), end(il), data);
	}

	vector(const vector& that) : vector(that.size())
	{
	    cout << "copy ctor\n";
	    copy_that(that);
	}

	vector(vector&& that) : s{that.s}, data{that.data}
	{
	    cout << "move ctor\n";
	    that.data= nullptr;
	    that.s= 0;
	}

	vector& operator=(const vector& that) &
	{
	    cout << "copy assg\n";
	    assert(s == that.s);
	    copy_that(that);
	    return *this;
	}

	vector& operator=(vector&& that) &
	{
	    cout << "move assg\n";
	    size_check(that.size());
	    // swap(data, that.data);
	    data= that.data;
	    that.data= nullptr;
	    that.s= 0;
	    return *this;
	}
	
	~vector() { delete[] data; }

	      Value& operator[](size_t i) &      { check(i); return data[i]; }
	const Value& operator[](size_t i) const& { check(i); return data[i]; }

	size_t size() const { return s; }

	void size_check(size_t ss) const { assert(s == ss); }
      private:
	size_t s;
	Value* data;
    };

    vector(size_t) -> vector<double>;
    
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
    
    template <typename Value>
    vector<Value> operator+(const vector<Value>& v1, const vector<Value>& v2)
    {
	size_t s= v2.size();
	v1.size_check(s);
	vector<Value> sum(s);
	// if (s == 0)
	//     return vector<Value>{};
	for (size_t i= 0; i < s; ++i)
	    sum[i]= v1[i] + v2[i];
	return sum;
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    vector v{4.8, 3.8, 9.1};
    cout << "v = " << v << endl;
    assert(abs(v[1] - 3.8) < 1e-12);

    // vector w{v};
    vector w(v);
    cout << "w = " << w << endl;

    v[0]= 666;
    w[1]= 999;
    cout << "v = " << v << endl;
    cout << "w = " << w << endl;

    vector x(w.size());
    x= w;
    cout << "x = " << x << endl;
    
    x= v + w;
    cout << "x = " << x << endl;
    
    vector y(x + v);
    cout << "y = " << y << endl;

    x= move(y);
    cout << "y = " << y << endl;

    vector z(move(x));
    cout << "x = " << x << endl;
    
    return 0;
}
  
 
