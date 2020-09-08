#include<iostream>
using namespace std;

// 重载递增运算符

// 自定义整型
class MyInteger{

    // 友元，用于访问私有属性
    friend ostream& operator<<(ostream& cout, MyInteger myint);

public:
    MyInteger(){
        m_Num = 0;
    };

    // 重载前置++运算符，返回的引用
    MyInteger& operator++(){
        // 先进行++运算
        m_Num++;
        // 再将自身做返回
        return *this;
    };

    // 重载后置++运算符,此次的int为占位符，用于区分前置和后置
    // 后置++运算符返回的是值，而不是引用
    MyInteger operator++(int){
        // 先记录当时的结果
        MyInteger tmp= *this;
        // 后递增
        m_Num++;
        // 最后将记录结果做返回
        return tmp;
    };

private:
    int m_Num;
};

ostream& operator<<(ostream& cout, MyInteger myint){
    cout << myint.m_Num;
    return cout;
};

void test01(){
    MyInteger myint;

    cout << ++myint << endl;
    cout << myint << endl;
};

void test02()
{
    MyInteger myint;

    cout << myint++ << endl;
    cout << myint << endl;
};

int main(){

    test01();
    test02();

    return 0;
}