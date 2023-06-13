// EJERCICIOS DE POLIMORFISMO DE AYEDA

#include <iostream>

using namespace std;
template<class T>
class A {
  private:
    T a_;
  public:
    A(T x) {a_ = x; };

    T f(int x) { 
      std::cout << "A::f" << std::endl;
      // std::cout << "x*x = " << x*x << std::endl;
      return g(x*x);
    };

    virtual T g(T x) {
      std::cout << "A::g" << std::endl;
      // std::cout << "x/a_ = " << x/a_ << std::endl;
      return (x / a_); 
    };
};

template<class T>
class B : public A<T> {
  private:
    T b_;
  public:
    B(T x = 3) : A<T>(x*x), b_(x) {};

    T f (int x) {
      std::cout << "B::f" << std::endl;
      return A<T>::f(x + b_); 
    };

    T g(T x) { 
      std::cout << "B::g" << std::endl;
      return x % b_;
    };
};

using T = int;

int main() {
  std::cout << "Ejercicio de polimorfismo - examen Mayo 22-23\n";
  A<T> a(10);
  std::cout << a.f(5) << std::endl;
  B<T> b;
  std::cout << b.f(3) << std::endl;

  A<T> *c = new B<T>(5);
  std::cout << c->f(3) << std::endl;
  return 0;
}