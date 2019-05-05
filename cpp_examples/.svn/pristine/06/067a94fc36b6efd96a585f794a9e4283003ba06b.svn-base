#include <iostream>
#include <typeinfo>
#include <utility>

using namespace std;

namespace ct {

    template <typename T>
    struct is_pointer
    {
	static constexpr bool value= false;
    };

    template <typename T>
    struct is_pointer<T*>
    {
	static constexpr bool value= true;
    };

    template <typename T>
    struct is_pointer<T const>
      : is_pointer<T> {};

    template <typename T>
    constexpr bool is_pointer_v= is_pointer<T>::value;
    
    template <typename T>
    void print_is_pointer1(T&)
    {
	cout << typeid(T).name() << (is_pointer<T>::value ? " is" : " is not")
	     << " pointer.\n";
    }
    
    template <typename T>
    void print_is_pointer2(T&)
    {
	cout << typeid(T).name() << (is_pointer_v<T> ? " is" : " is not")
	     << " pointer.\n";
    }

    template <bool Condition, typename T= void>
    struct enable_if
    {
	using type= T;
    };

    template <typename T>
    struct enable_if<false, T>
    {};

    template <bool Condition, typename T= void>
    using enable_if_t= typename enable_if<Condition, T>::type;
    
    template <typename T>
    typename enable_if<is_pointer_v<T>, void>::type pointer_only1(T)
    {
	cout << typeid(T).name() << " is pointer.\n";
    }
    
    template <typename T>
    enable_if_t<is_pointer_v<T>> pointer_only2(T)
    {
	cout << typeid(T).name() << " is pointer.\n";
    }

    template <typename T, typename = enable_if_t<is_pointer_v<T>>>
    void  pointer_only3(T)
    {
	cout << typeid(T).name() << " is pointer.\n";
    }

    template <typename T>
    enable_if_t<is_pointer_v<T>> print_value1(T x)
    {
	cout << "The value is " << *x << endl;
    }
    
    template <typename T>
    enable_if_t<! is_pointer_v<T>> print_value1(T x)
    {
	cout << "The value is " << x << endl;
    }

    template <bool Value>
    struct bool_constant
    {
	static constexpr bool value= Value;
    };

    using true_type= bool_constant<true>;
    using false_type= bool_constant<false>;
    
    template <typename T>
    void print_value2_aux(T x, true_type)
    {
	cout << "The value is " << *x << endl;
    }

    template <typename T>
    void print_value2_aux(T x, false_type)
    {
	cout << "The value is " << x << endl;
    }
    
    template <typename T>
    void print_value2(T x)
    {
	print_value2_aux(x, bool_constant<is_pointer_v<T>>{});
    }

    template <typename T>
    void print_value3(T x)
    {
	if constexpr (is_pointer_v<T>) // C++17
	    cout << "The value is " << *x << endl;
	else
	    cout << "The value is " << x << endl;	    
    }   

    struct vehicle {};
    struct car : vehicle {};

    // template <typename T>
    // struct is_vehicle
    //   : false_type {};

    // template <>
    // struct is_vehicle<vehicle>
    //   : true_type {};

    constexpr false_type is_a_vehicle(...) { return {}; }
   
    constexpr true_type is_a_vehicle(const vehicle&) { return {}; }

    template <typename T>
    constexpr bool is_vehicle= decltype(is_a_vehicle(declval<T>()))::value;
    
    template <typename T>
    void print_is_vehicle(T)
    {
	cout << typeid(T).name() << (is_vehicle<T> ? " is" : " is not")
	     << " vehicle.\n";
    }

}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    print_is_vehicle(3);
    print_is_vehicle(vehicle{});
    print_is_vehicle(car{});

    int i{3};
    int* ip{&i};
    int const* const  cp{&i};
    print_is_pointer1(i);
    print_is_pointer1(ip);
    print_is_pointer1(cp);
    cout << endl;

    print_is_pointer2(i);
    print_is_pointer2(ip);
    print_is_pointer2(cp);
    cout << endl;

    // pointer_only1(i);
    pointer_only1(ip);

    // pointer_only2(i);
    pointer_only2(ip);

    // pointer_only3(i);
    pointer_only3(ip);
    cout << endl;

    print_value1(i);
    print_value1(ip);
    cout << endl;
    
    print_value2(i);
    print_value2(ip);
    cout << endl;
    
    print_value3(i);
    print_value3(ip);
    cout << endl;
    
    return 0;
}
  
 
