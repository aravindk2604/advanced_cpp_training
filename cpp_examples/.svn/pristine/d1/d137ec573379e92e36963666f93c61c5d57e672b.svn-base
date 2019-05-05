#include <iostream>
#include <memory>

using namespace std;

// Stolen from Rainer Grimm
struct Son;
struct Daughter;

struct Mother{
  ~Mother(){
    std::cout << "Mother gone" << std::endl;
  }
  void setSon(const std::shared_ptr<Son>& s ){
    mySon= s;
  }
  void setDaughter(const std::shared_ptr<Daughter>& d ){
      myDaughter= d;
  }

    void scoldWithSon() {
	shared_ptr<const Son> sp= mySon.lock();
	if (sp != nullptr)
	    std::cout << "How dare you?!\n";
    }
    
  std::weak_ptr<const Son>    mySon;
  std::weak_ptr<const Daughter> myDaughter;
};

struct Son{
  Son(std::shared_ptr<Mother> m):myMother(m){}
  ~Son(){
    std::cout << "Son gone" << std::endl;
  }
  std::shared_ptr<const Mother> myMother;
};

struct Daughter{
  Daughter(std::shared_ptr<Mother> m):myMother(m){}
  ~Daughter(){
    std::cout << "Daughter gone" << std::endl;
  }
  std::shared_ptr<const Mother> myMother;
};

int main(){
  std::cout << std::endl;
  {
    shared_ptr<Mother> mother= make_shared<Mother>();
    shared_ptr<Son> son = make_shared<Son>(mother);
    shared_ptr<Daughter> daughter = make_shared<Daughter>(mother);
    
    mother->setSon(son);
    mother->setDaughter(daughter);

    mother->scoldWithSon();
  }
  std::cout << std::endl;
}




