#include <iostream>

class Base {
public:
    Base(int x) {
        std::cout << "Constructor de Base)" << std::endl;
        foo();
    }
    virtual void foo() {
        std::cout << "Base::foo()" << std::endl;
    }
};

class Derived1 : public Base {
public:
    Derived1() : Base(5) {
        std::cout << "Constructor Derived1" << std::endl;
        foo();
    }
    void foo() override {
        std::cout << "Derived1::foo()" << std::endl;
    }
};

class Derived2 : public Derived1 {
public:
    void foo() override {
        std::cout << "Derived2::foo()" << std::endl;
    }
};

int main() {
    Base base(8);
    base.foo();
    std::cout << std::endl;

    Derived1 derived1;
    derived1.foo();

    std::cout << std::endl;
    Derived1* derived2 = new Derived2();
    derived2->foo();

    return 0;
}
