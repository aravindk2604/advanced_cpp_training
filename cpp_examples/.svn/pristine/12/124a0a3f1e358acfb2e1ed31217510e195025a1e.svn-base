#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <typeinfo>
#include <memory>

using namespace std;

namespace ct {

    struct base
    {
	int f(int i) { return i + k; }
	int g(int i) {
	    auto lambda= [i, this](int j) { return f(j + i + k); };
	    return lambda(2*i); 
	}
	int k{9};
    };

    // C++14
    template <typename Container>
    void reverse_sort(Container& c)
    {
	// sort(begin(c), end(c), [](auto x, auto y){ return x > y; }); // C++14
	// C++11:
	using reftype= decltype(*begin(c));
	sort(begin(c), end(c), [](reftype x, reftype y){ return x > y; });
    }

    auto scale_factory(int factor)
    {
	unique_ptr<int> up{ new int{factor} };
	// return [up](int x){ return *up * x; }; // no copy ctor in unique_ptr
	// return [&up](int x){ return *up * x; }; // stale ref to deleted pointer
	return [u= move(up)](int x){ return *u * x; };
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    vector<int> v{4, 9, 2, 8, 7}, w(v.size());
    // sort(begin(v), end(v), [](int x, int y){ return x > y; });
    reverse_sort(v);    
    copy(begin(v), end(v), ostream_iterator<int>(cout, " ")); cout << endl;

    int factor= 7;
    transform(begin(v), end(v), begin(w), [factor](int x){ return factor * x; }); 
    copy(begin(w), end(w), ostream_iterator<int>(cout, " ")); cout << endl;

    ++factor;
    auto scale= [factor](int x) ->int { return factor * x; };
    transform(begin(v), end(v), begin(w), scale);
    copy(begin(w), end(w), ostream_iterator<int>(cout, " ")); cout << endl;

    cout << "type of scale is " << typeid(scale).name() << endl;

    auto scale_ref= [&factor](int x){ return factor * x; };
    cout << "scale(6) = " << scale(6) << endl;
    cout << "scale_ref(6) = " << scale_ref(6) << endl;

    ++factor;
    cout << "scale(6) = " << scale(6) << endl;
    cout << "scale_ref(6) = " << scale_ref(6) << endl;

    auto sf= scale_factory(7);
    cout << "scale_factory(7)(8) = " << sf(8) << endl;

    
    return 0;
}
  
 
