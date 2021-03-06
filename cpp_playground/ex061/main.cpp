#include "meyers_singleton.hpp"
#include <iostream>

class MyClass1 {
    public:
        void test(){
            std::cout << "MyClass1 member function" << std::endl; 
            singleton::get_instance().increment(5);
            singleton::get_instance().fun1();
            singleton::get_instance().fun2();
            singleton::get_instance().fun3();
            singleton::get_instance().print();
        }
};

class MyClass2 {
    public:
        void test(){
            std::cout << "MyClass2 member function" << std::endl; 
            singleton::get_instance().increment(10);
            singleton::get_instance().fun1();
            singleton::get_instance().fun2();
            singleton::get_instance().fun3();
            singleton::get_instance().print();
        }
};

int main(){
    MyClass1 obj1;
    MyClass2 obj2;
    obj1.test();
    obj2.test();

    return 0;
}
