#include <iostream>
#include <tuple>
#include <functional>

using namespace std;

namespace ct {

    template <typename ...Args>
    auto get_third(Args&& ...a)
    {
	static_assert(sizeof...(a) >= 3,
		      "Not enough arguments.");
	tuple<Args...> t{a...};
	return get<2>(t);
    }
    
    template <typename ...Args>
    auto get_int(Args&& ...a)
    {
	tuple<Args...> t{a...};
	return get<int>(t);
    }
    
    template <typename ...Args>
    class call_later
    {
	template <typename F, size_t ...I>
	void call_helper(F f, index_sequence<I...>)
	{
	    f(get<I>(para)...);
	}
      public:
	template <typename ...Args2>
	call_later(Args2&& ...a)
	  : para{forward<Args2>(a)...}
	{}

	template <typename F>
	void call(F f)
	{
	    // index_sequence<0, 1, 2, ..., sizeof...(Args)-1>
	    call_helper(f, make_index_sequence<sizeof...(Args)>{});
	    // apply(f, para); // C++17
	}
	
      private:
	tuple<Args...> para;
    };

    void f(int i, float f, double d)
    {
	cout << "called f(" << i << ", " << f << ", " << d << ")\n";
    }
    
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    call_later<int, float, double> parameters{5, 5.4f, 6.3};
    parameters.call(f);
    
    cout << get_third(1, 2, 3, 4, 5, 6) << endl;
    // cout << get_third(1, 2) << endl;

    cout << get_int(4.4, 8.3, 4.4f, 8u, 9l, 4, 1l);

    

    return 0;
}
  
 
