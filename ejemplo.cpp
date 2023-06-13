#include <iostream>

using namespace std;

// class Base {
//  public:
//   void print() {
//     cout << "Base Function" << endl;
//   }
// };

// class Derived : public Base {
//  public:
//   void print() {
//     cout << "Derived Function" << endl;
//   }
// };

// int main() {
//   // Derived derived;
//   Base* pointer = new Derived;
//   // Call function of Base class using pointer
//   pointer->print();
//   return 0;
// }


class A {
 public:
  void f(void)         { cout << "A::f() + "; g(); }
  virtual void g(void) { cout << "A::g()" << endl; }
};

class B: public A {
 public:
  virtual void g(void) { cout << "B::g()" << endl; }
};

int main() { 
  A a;
  B b;
  a.f(); // A::f() + A::g() 
  b.g(); // B::g()
  b.f(); // A::f() + B::g()
}
