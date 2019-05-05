#include <iostream>
#include <cmath>

using namespace std;

namespace ct {

    constexpr float square(float x) { return x * x; }

    template <typename T>
    constexpr T square(T x) { return x * x; }

    constexpr size_t popcount(size_t n)
    {
	size_t count{0};
	for (; n != 0; ++count)
	    n&= n - 1;
	return count;
    }

    constexpr size_t popcount11(size_t n)
    {
	return n == 0 ? 0 : popcount11(n & n-1) + 1;
    }

    constexpr bool is_prime(size_t n)
    {
	if (n == 1)
	    return false;
	if (n % 2 == 0)
	    return n == 2;
	size_t max_check= ceil(sqrt(n)); // only on g++
	for (size_t i= 3; i < max_check; i+= 2)
	    if (n % i == 0)
		return false;
	return true;
    }
    
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    constexpr float sq37= square(3.7f);
    constexpr double sq38= square(3.8);

    cout << "popcount(0b1001'0100'1000) = " << popcount(0b1001'0100'1000) << endl;
    cout << "popcount11(0b1001'0100'1000) = " << popcount11(0b1001'0100'1000) << endl;

    constexpr bool is_p= is_prime(982'451'653);
    cout << "982'451'653 is " << (is_p ? "" : "not ") << "a prime number.\n";
    
    return 0;
}
  
 
