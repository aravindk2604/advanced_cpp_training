#include <iostream>
#include <functional>
#include <string>
#include <map>

using namespace std;

namespace ct {

    int add(int x, int y) { return x + y; }

    template <typename T>
    T mul(T x, T y) { return x * y; }

    struct minus
    {
	int operator()(int x, int y) const { return x - y; }
    };

    template <typename T>
    struct div
    {
	T operator()(T x, T y) const { return x / y; }
    };

    struct power
    {
	template <typename T>
	T operator()(T x, T y) const
	{
	    T res{1};
	    for (T i{0}; i < y; ++i)
		res*= x;
	    return res;
	}
    };

    struct maxi
    {
	static int eval(int x, int y) { return x > y ? x : y; }
	int run(int x, int y) const { return x > y ? x : y; }
    };
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    using binfun= function<int(int, int)>;
    binfun f= add;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= mul<int>;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= ct::minus{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= ct::div<int>{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= power{};
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= [](int x, int y){ return x % y; };
    cout << "f(7, 3) = " << f(7, 3) << endl;

    f= maxi::eval;
    cout << "f(7, 3) = " << f(7, 3) << endl;

    maxi m; 
    f= bind(&maxi::run, m, placeholders::_1, placeholders::_2);
    cout << "f(7, 3) = " << f(7, 3) << endl;
    
    f= [m](int x, int y){ return m.run(x, y); };
    cout << "f(7, 3) = " << f(7, 3) << endl;

    map<string, binfun> ff{{"plus", add}, {"up to", power{}},
			   {"modulo", [](int x, int y){ return x % y; }}};

    cout << "9 plus 4 is " << ff["plus"](9, 4) << endl;
    
    for (auto [name, op] : ff)
	cout << "9 " << name << " 4 is " << op(9, 4) << endl;
    
    return 0;
}
  
 
