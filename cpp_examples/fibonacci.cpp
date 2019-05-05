#include <iostream>
#include <string>

using namespace std;

namespace ct {

    template <size_t N>
    struct fibonacci
    {
	static const size_t value= fibonacci<N-1>::value + fibonacci<N-2>::value;
    };

    template <>
    struct fibonacci<1>
    {
	static const size_t value= 1;
    };

    template <>
    struct fibonacci<2>
      : fibonacci<1> {};

    constexpr size_t fibo(size_t n)
    {
	return n < 2 ? n : fibo(n-1) + fibo(n-2);
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    cout << "Fibonacci number 15 = " << fibonacci<15>::value << endl;
    cout << "Fibonacci number 14 = " << fibo(14) << endl;

    int i= 2;
    if (argc > 1)
	i= stoi(argv[1]);
    cout << "Fibonacci number " << i << " = " << fibo(i) << endl;

    fibonacci<fibo(5)> ff5;

    constexpr size_t fibo210= fibo(210);
    cout << "Fibonacci number 210 = " << fibo210 << endl;

    const int j= 5; // not known at compile time

    constexpr size_t fiboj= fibo(j);

    return 0;
}
  
 
