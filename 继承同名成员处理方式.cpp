#include<iostream>
using namespace std;

/*

1、访问子类同名成员，直接访问即可
2、访问父类同名成员，需要加作用域
3、当子类与父类拥有同名的成员函数，子类会隐藏父类中的同名成员函数，
   加作用域可以访问到父类中的同名函数

*/

class Base{
public:

    int m_A;
    Base(){
        m_A = 100;
    };

    void func(){
        cout << "Base - func()调用" << endl;
    };
};

class Son: public Base{

public:
    int m_A;
    Son(){
        m_A = 200;
    };

    void func(){
        cout << "Son - func()调用" << endl;
    };
};

void test01(){
    Son son;
    cout << "Son  中的 m_A = " << son.m_A << endl;
    // 调用子类的同名属性需要加上作用域
    cout << "Base 中的 m_A = " << son.Base::m_A << endl;
};

// 同名成员函数的调用
void test02(){
    Son son;
    son.func();  // 直接调用，调用的是子类中的函数

    son.Base::func(); // 加上作用域来调用父类中的同名函数
    // cout << son.func() << endl;
};

int main(){

    // test01();
    test02();

    return 0;
}