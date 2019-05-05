#include <iostream>

using namespace std;

namespace ct {

    template <typename T>
    struct base
    {
	using value_type= T;
	T f(T i) { return i + k; }
	T k{9};
    };

    // who writes such code deserves being fired
    template <>
    struct base<short>
    {
	void value_type() {}
	using f= short;
	using k= int;
    };

    template <typename T>
    struct derived : base<T>
    {
	T g(T i) {
	    // value_type j= i + 4;
	    // j+= k;
	    // return f(j + i);
	    typename base<T>::value_type j= i + 4;
	    j+= this->k; // j+= base<T>::k;
	    return this->f(j + i); // return base<T>::f(j + i);
	}
    };
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    derived<int> d1;
    cout << d1.g(4) << endl;

    derived<int>::value_type i= 9;

    derived<short> d2;
    // cout << d2.g(4) << endl;
    
    return 0;
}
  
 
