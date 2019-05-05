#include <iostream>
#include <memory>

using namespace std;

namespace ct {

    void f(unique_ptr<int> up) {     }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    unique_ptr<int> up0;
    if (up0 == nullptr)
	cout << "up0 is indeed a nullptr.\n";

    if (! up0)
	cout << "up0 is indeed a nullptr.\n";

    unique_ptr<int> up1{ new int{9} };
    cout << "*up1 = " << *up1 << endl;

    // unique_ptr<int> up2{ up1 };

    unique_ptr<int> up3{ move(up1) };
    cout << "*up3 = " << *up3 << endl;
    if (up1 == nullptr)
	cout << "up1 is now a nullptr.\n";

    unique_ptr<int> up4;
    // up4= up3;

    up4= move(up3);
    //  up4.reset( up3.release() );
    
    cout << "*up4 = " << *up4 << endl;
    if (up3 == nullptr)
	cout << "up3 is now a nullptr.\n";

    // Double allocation
    // unique_ptr<int> up5{ up4.get() };

    int i{4};
    // unique_ptr<int> up6{ &i };

    unique_ptr<int[]> up7{ new int[11] };
    up7[0]= 12;
    cout << "up7[0] = " << up7[0] << endl;

    auto up8= make_unique<int>(13);
    cout << "*up8 = " << *up8 << endl;
    
    return 0;
}
  
 
