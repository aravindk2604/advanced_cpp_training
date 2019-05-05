#include <iostream>

using namespace std;

namespace ct {

    struct ole_c_complex
    {
	double re, im;
    };   

    struct empty {};

    template <typename T>
    void f(T x)
    {
	T e1;   // Default ctor, intrinsic types uninitialized
	// T e2(); // Function declaration
	T e3{}; // Default ctor, intrinsic type value-init. (0, nullptr)
    }
    
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    // int i1= 3.5; // warning in clang++
    // int i2(3.6); // ditto 
    // int i3{3.7};
    // int i4= {3.8};

    int i5{7};
    unsigned u1{9};

    // unsigned u2{i5};
    // int i6{u1};

    static_assert(sizeof(long) > sizeof(unsigned),
		  "long not longer than unsigned here.");
    
    long l1{u1}; // won't compile on VS
    int  i7{1234567890}; // int must be 32 bit at least

    long double ld1{4.98};
    double d6{9.2};
    ole_c_complex c1{3.4, 5.1} /*, c2{5.1, ld1} narrowing */; 
    cout << "c1 = (" << c1.re << ", " << c1.im << ")\n";
    
    ct::empty e1;
    // ct::empty e2(); // Function declaration
    ct::empty e3{};


    return 0;
}
  
 
