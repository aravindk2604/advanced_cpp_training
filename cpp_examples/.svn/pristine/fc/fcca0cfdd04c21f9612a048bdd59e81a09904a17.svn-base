#include <iostream>
#include <tuple>
#include <string>
#include <unordered_map>

using namespace std;

namespace ct {

    auto create()
    {
	return tuple{3, 8.4, "Hi world"s};
    }
    
    struct ole_c_complex
    {
	double re, im;
    };

    ole_c_complex some_constant()
    {
	return ole_c_complex{4.5, 9.2};
    }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    auto [real_part, ipart]= some_constant();
    cout << "real_part = " << real_part << endl;

    auto t1= create();
    auto t1_0= get<0>(t1);
    cout << "t1_0 = " << t1_0 << endl;

    int i2;
    double d2;
    string s2;
    tie(i2, d2, s2)= create();
    cout << "i2 = " << i2 << endl;

    auto [i3, d3, s3]= create();
    cout << "i3 = " << i3 << endl;

    unordered_map<string, int> phone{{"Fred", 345}, {"Horst", 644},
				     {"Gerd ", 123}};

    for (pair<const string, int> entry : phone)
	cout << entry.first << "'s number is " << entry.second << ".\n";

    for (auto [name, number] : phone)
	cout << name << "'s number is " << number << ".\n";

    return 0;
}
  
 
