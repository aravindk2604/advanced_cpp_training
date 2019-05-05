#include <iostream>
#include <memory>

using namespace std;

namespace ct {

    void f(shared_ptr<int> sp) {     }
}

int main (int argc, char* argv[]) 
{
    using namespace ct;

    shared_ptr<int> sp0;
    if (sp0 == nullptr)
	cout << "sp0 is indeed a nullptr.\n";
    
    if (! sp0)
	cout << "sp0 is indeed a nullptr.\n";

    shared_ptr<int> sp1{ new int{9} };
    cout << "*sp1 = " << *sp1 << endl;

    shared_ptr<int> sp2{ sp1 };
    cout << "*sp2 = " << *sp2 << ", used "
	 << sp2.use_count() << " times.\n";

    shared_ptr<int> sp3{ move(sp2) };
    cout << "*sp3 = " << *sp3 << ", used "
	 << sp3.use_count() << " times.\n";
    if (sp2 == nullptr)
	cout << "sp2 is now a nullptr.\n";

    shared_ptr<int> sp4;
    sp4= sp3;
    cout << "*sp4 = " << *sp4 << ", used "
	 << sp4.use_count() << " times.\n";

    sp0= move(sp1);
    cout << "*sp0 = " << *sp0 << ", used "
	 << sp0.use_count() << " times.\n";
    if (sp1 == nullptr)
	cout << "sp1 is now a nullptr.\n";

    // Double allocation
    // shared_ptr<int> sp5{ sp4.get() };
    // cout << "*sp4 = " << *sp4 << ", used "
    // 	 << sp4.use_count() << " times.\n";
    // cout << "*sp5 = " << *sp5 << ", used "
    // 	 << sp5.use_count() << " times.\n";

    auto sp8= make_shared<int>(13);
    cout << "*sp8 = " << *sp8 << endl;

    shared_ptr<int> sp9{ new int[13], [](int* p){ delete[] p; } };
    int* rp= new int{17};

    f(shared_ptr<int>{ rp, [](int*){ cout << "we didn't delete :-P\n"; } });

    delete rp;
    
    return 0;
}
  
 
