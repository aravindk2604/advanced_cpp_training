#include <iostream>
#include <cassert>
#include <initializer_list>
#include <algorithm>

using namespace std;

namespace ct {

    template <typename Value>
    class vector_sum;

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

	vector& operator=(vector_sum<Value> that) &
	{
	    size_check(that.size());
	    for (size_t i= 0; i < s; ++i)
		data[i]= that[i];
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

#if 0
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
#endif
    
    template <typename Value>
    class vector_sum
    {
      public: 
	vector_sum(const vector<Value>& v1, const vector<Value>& v2) : v1{v1}, v2{v2}
	{
	    v1.size_check(v2.size());
	}

	size_t size() const { return v1.size(); }

	Value operator[](size_t i) { return v1[i] + v2[i]; }
      private:
	const vector<Value>& v1;
	const vector<Value>& v2;
    };

    template <typename Value>
    vector_sum<Value> operator+(const vector<Value>& v1, const vector<Value>& v2)
    {
	return vector_sum<Value>{v1, v2};
    }

    template <typename Value>
    void add(const vector<Value>& v1, const vector<Value>& v2, vector<Value>& sum)
    {
	size_t s= v2.size();
	v1.size_check(s);
	sum.size_check(s);
	for (size_t i= 0; i < s; ++i)
	    sum[i]= v1[i] + v2[i];
    }

    
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    vector v{4.8, 3.8, 9.1}, w{2.8, 4.4, 6.1};
    cout << "v = " << v << endl;
    cout << "w = " << w << endl;

    vector x(w.size());
    
    x= v + w;
    cout << "x = " << x << endl;

    add(v, w, x);
    cout << "x = " << x << endl;
    
    return 0;
}
  
 
