#include<iostream>
using namespace std;

// 继承中同名静态成员处理方式
class Base{
public:
    static int m_A;
    static void func(){
        cout << "Base - static void func()" << endl;
    };
};

// 静态成员变量：类内声明，类外初始化
int Base::m_A = 100;


class Son: public Base{
public:
    static int m_A;

    static void func(){
        cout << "Son  - static void func()" << endl;
    };
};

int Son::m_A = 200;

void test01(){
    // 1、通过对象来访问
    cout << "通过对象来访问" << endl;
    Son s;
    cout << "Son  下的 m_A = " << s.m_A << endl;
    cout << "Base 下的 m_A = " << s.Base::m_A << endl;

    // 2、通过类名来访问
    cout << endl;
    cout << "通过类名来访问" << endl;
    cout << "Son   下的 m_A = " << Son::m_A << endl;
    // 第一个::代表通过类名方式访问， 第二个::代表访问父类作用域下
    cout << "Base  下的 m_A = " << Son::Base::m_A << endl;

};

void test02(){

    // 1、通过对象访问
    cout << "通过对象的方式访问同名的静态成员函数" << endl;
    Son s;
    s.func();
    s.Base::func();

    // 2、通过类名的方式访问
    cout << endl;
    cout << "通过类名的方式访问同名的静态成员函数" << endl;
    Son::func();
    Son::Base::func();
};


int main(){

    // test01();
    test02();

    return 0;
}