#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

namespace ct {
    template <typename Container>
    constexpr auto find_first_multiple(Container& v, int val)
    {
	return find_if(begin(v) , end(v), [val](int x) { return x%val == 0;} );
    }
}

int main () 
{
    using namespace ct;

    // vector<int> vi{3, 5, 4, 12, 15, 7, 9};
    int vi[]= {3, 5, 4, 12, 15, 7, 9};
    for (int i= 2; i < 10; ++i) 
    {
        auto it = find_first_multiple(vi, i);
        if ( it != end(vi)) 
            cout << "The first multiple of " << i << " is " << *it << endl;
        else
            cout << "There is no multiple of " << i << endl;
    }
        
    return 0;
}
  
 