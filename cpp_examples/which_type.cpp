#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <memory>

using namespace std;

template <typename T> struct w {};

template <typename T>
void cp(T arg)
{
    cout << "T is " << typeid(T).name() << ", arg is "
	 << typeid(arg).name() << endl;
}

template <typename T>
void cr(const T& arg)
{
    cout << "T is " << typeid(w<T>).name() << ", arg is "
	 << typeid(w<decltype(arg)>).name() << endl;
}

template <typename T>
void mr(T& arg)
{
    cout << "T is " << typeid(w<T>).name() << ", arg is "
	 << typeid(w<decltype(arg)>).name() << endl;
}
    
template <typename T>
void fr(T&& arg)
{
    cout << "T is " << typeid(w<T>).name() << ", arg is "
	 << typeid(w<decltype(arg)>).name() << endl;
}

template <typename T>
void pass_on(T&& arg)
{
    // fr(arg); always lvalue
    // fr(move(arg)); // always rvalue
    fr(forward<T>(arg));
}

struct quad
{
    quad() = default;
    quad(int i, int j, int k, int l) {}
    quad(double) {}
};

// Create unique_ptr<Target> while calling constructor with args
template <typename Target, typename ...Args>
unique_ptr<Target> our_make_unique(Args&& ...args)
{
    return unique_ptr<Target>{ new Target{ forward<Args>(args)... } };
}

template <typename T>
void rvalue_only(w<T>&&)
{
    cout << "It's an rvalue.\n";
}

template <typename T>
void rvalue_only1(T&&)
{
    cout << "It's an rvalue.\n";
}

template <typename T>
void rvalue_only1(T&) = delete;

void double_only(double)
{
    cout << "It's a double.\n";
}

template <typename T> void double_only(T) = delete;

template <typename T>
void rvalue_only2(T&& arg)
{
    static_assert(is_rvalue_reference<decltype(arg)>::value,
		  "Function only allowed for rvalues.");
    cout << "It's an rvalue.\n";
}

int main (int argc, char* argv[]) 
{
    unique_ptr<quad> uq1= our_make_unique<quad>();
    unique_ptr<quad> uq2= our_make_unique<quad>(4.2);
    unique_ptr<quad> uq3= our_make_unique<quad>(3, 8, 2, 9);


    int        i{4};
    int&       r{i};
    const int& c{i};

    rvalue_only1(3);
    // rvalue_only2(i);
    
    rvalue_only2(3);
    // rvalue_only1(i);
    
    w<int> wi;
    rvalue_only(w<int>{});
    // rvalue_only(wi);

    double_only(3.0);
    // double_only(3);

    cp(3);
    cp(i);
    cp(r);
    cp(c);
    cout << endl;

    cr(3);
    cr(i);
    cr(r);
    cr(c);
    cout << endl;

    // mr(3);
    mr(i);
    mr<int&>(i);
    mr<int&&>(i);
    mr(r);
    mr(c);
    cout << endl;

    fr(3);
    // fr<int&&>(3);
    fr(i);
    fr(r);
    fr(c);
    cout << endl;

    pass_on(3);
    pass_on(i);
    pass_on(r);
    pass_on(c);
    cout << endl;

    return 0;
}
  
 
