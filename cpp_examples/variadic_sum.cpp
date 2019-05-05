#include <iostream>
#include <type_traits>

using namespace std;

namespace ct {

#if 0
    typedef double real;
    typedef int  array_type[4];
    typedef int (*f_type)(int, int);

#else
    using real= double;
    using array_type= int[4];
    using f_type= int (*)(int, int);
#endif
    
    template <typename T>
    T sum(T x) { /* cout << "sum(T)\n"; */ return x; }

    // Template variables since C++11
    // Used for type_traits since C++14
    // Like common_type_t
    template <typename ...Args>
    using ct= typename common_type<Args...>::type;
    
    template <typename First, typename ...Rest>
    // First
    // typename common_type<First, Rest...>::type // C++11
    // ct<First, Rest...>
    auto // C++14
    sum(First f, Rest ...r)
    {
	// cout << "sum with " << sizeof...(r)+1 << " values\n";
	return f + sum(r...);
    }

    // C++17
    // like sum, right-associative without unit element
    template <typename ...Args>
    auto sumr(Args ...a)
    {
	return (a + ...);
    }
	
    // right-associative with unit element
    template <typename ...Args>
    auto sumr0(Args ...a)
    {
	return (a + ... + 0);
    }
	
    // left-associative without unit element
    template <typename ...Args>
    auto suml(Args ...a)
    {
	return (... + a);
    }
	
    // left-associative with unit element
    template <typename ...Args>
    auto suml0(Args ...a)
    {
	return (0 + ... + a);
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    // cout << "sum(-2.6) = " << sum(-2.6) << endl;
    // cout << "sum(9u, -2.6) = " << sum(9u, -2.6) << endl;
    // cout << "sum(3.7f, 9u, -2.6) = " << sum(3.7f, 9u, -2.6) << endl;
    // cout << "sum(-7, 3.7f, 9u, -2.6) = " << sum(-7, 3.7f, 9u, -2.6) << endl;
    cout << "sum(-7, 3.7f, 9u, -42.6) = " << sum(-7, 3.7f, 9u, -42.6) << endl;
    cout << "sumr(-7, 3.7f, 9u, -42.6) = " << sumr(-7, 3.7f, 9u, -42.6) << endl;
    cout << "sumr0() = " << sumr0() << endl;

    cout << "sumr(1.0, -1.0, 1e-20) = " << sumr(1.0, -1.0, 1e-20) << endl;
    cout << "suml(1.0, -1.0, 1e-20) = " << suml(1.0, -1.0, 1e-20) << endl;

    return 0;
}
  
 
