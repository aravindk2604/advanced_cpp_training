#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

namespace ct {

    template <typename T> struct w {};
    
    int& fref() { static int i{9}; return i; }
    const int& cref() { static int i{9}; return i; }

    template <typename Container>
    void print_all98(const Container& c)
    {
	for (typename Container::const_iterator it= c.begin(); it != c.end(); ++it)
	    cout << *it << " ";
	cout << endl;
    }

    template <typename Container>
    void print_all11(const Container& c)
    {
	for (auto it= begin(c), e= end(c); it != e; ++it)
	    cout << *it << " ";
	cout << endl;
    }

    template <typename Container>
    void print_all_for_copy(const Container& c)
    {
	for (auto value : c)
	    cout << value << " ";
	cout << endl;
    }
   
    template <typename Container>
    void print_all_for_ref(const Container& c)
    {
	for (auto& value : c)
	    cout << value << " ";
	cout << endl;
    }
   
    template <typename Container>
    void print_all_for_forward(const Container& c)
    {
	for (auto&& value : c)
	    cout << value << " ";
	cout << endl;
    }

    // C++14
    // -----
    
    template <typename Container>
    void print_all_for_da(const Container& c)
    {
	for (decltype(auto) value : c)
	    cout << value << " ";
	cout << endl;
    }

    struct empty_container {};
    
    template <typename Container>
    auto first_entry_copy(Container& c)
    {
	if (c.empty())
	    throw empty_container{};
	return *begin(c);
    }
    
    template <typename Container>
    decltype(auto) first_entry_as_is(Container& c)
    {
	if (c.empty())
	    throw empty_container{};
	return *begin(c);
    }

    template <typename Container>
    auto first_entry_11(Container& c) -> decltype(*begin(c))
    {
	if (c.empty())
	    throw empty_container{};
	return *begin(c);
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    // auto a0;
    auto a1= 5.3;              // double
    auto a2= 5.6f + 9u + 42.2; // double

    auto a3= fref();           // int
    auto& a4= fref();          // int&
    const auto& a5= fref();    // int const&

    auto a6= cref();           // int
    auto& a7= cref();          // const int& (auto becomes const int)
    cout << "a7 is " << typeid(w<decltype(a7)>).name() << endl;

    auto&& a8{9};
    auto&&  a9= fref();
    cout << "a9 is " << typeid(w<decltype(a9)>).name() << endl;

    decltype(fref()) a10= fref(); // int&
    decltype(5.6f + 9u + 42.2) a11; // double

    // C++14
    decltype(auto) a12= fref();   // int&, deduces like decltype, used like auto

    vector<int> v{4, 9, 8, 11};
    print_all98(v);
    print_all11(v);
    print_all_for_copy(v);
    print_all_for_ref(v);

    auto a13= 6.7, a14= 5.8;

    cout << "first_entry_copy(v) = " << first_entry_copy(v) << endl;
    cout << "first_entry_as_is(v) = " << first_entry_as_is(v) << endl;
    
    return 0;
}
  
 
