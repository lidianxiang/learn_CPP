#include<iostream>
using namespace std;

// 静态成员函数，所以对象共享同一个函数，静态成员函数只能访问静态成员变量
class Person{
public:
    static void fun(){
        m_A = 100;
        // m_B = 100; // 静态成员变量不可以访问非静态成员变量
        cout << "static void fun()函数的调用" << endl;
    };

    static int m_A; // 静态成员变量
    int m_B; // 非静态成员变量
};

// 静态成员变量需要在类外初始化
int Person::m_A = 0;

void test01(){
    // 1、通过对象访问
    Person p;
    p.fun();
    // 2、通过类名访问
    Person::fun();
};


int main(){

    test01();
    return 0;
}