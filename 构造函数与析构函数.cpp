#include<iostream>
using namespace std;
/*
构造函数语法： 类名(){}
1、构造函数，没有返回值，也不写void
2、函数名称与类名相同
3、构造函数可以有参数，因此可以发生重载
4、程序在调用对象时候会自动调用构造，无需手动调用，而且只会调用一次

析构函数语法: ~类名(){}
1、析构函数，没有返回值也不写void
2、函数名称与类名相同
3、析构函数不可以有参数，因此不可以发生重载
4、程序在对象销毁前会自动调用析构，无需手动调用，而且只会调用一次

*/

class Person{
public:
    // 构造函数
    Person(){
        cout << "Person 构造函数的调用" << endl;
    };

    // 析构函数
    ~Person(){
        cout << "Person 析构函数的调用" << endl;
    };
};

void test01(){
    Person p;  // 栈区的数据，test01()函数在执行完毕后，会释放这个对象
};

int main(){

    test01();

    return 0;
}