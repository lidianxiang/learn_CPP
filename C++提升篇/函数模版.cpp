#include<iostream>
using namespace std;

/*

C++另一种编程思想： 泛型编程，主要利用的技术就是模版

模版主要分为两种：函数模版和类模版

函数模版的作用： 建立一个通用函数，其函数返回值类型和形参类型可以不具体指定，用一个虚拟的类型来代表。

语法：
template<typename T>
函数声明或定义

模版的概念：模版就是建立通用的模具，大大提高复用性

*/

// 交换两个整型的函数
void swapInt(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
};

// 交换两个浮点型
void swapDouble(double &a ,double &b){
    double temp = a;
    a = b;
    b = temp;
};

// 函数模版
template<typename T> // 声明一个模版，告诉编译器后面的代码中紧跟这T不要报错，T是一个通用数据类型
void mySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
};

void test01(){
    int a = 10;
    int b = 20;
    cout << "交换前: " << endl;
    cout << "a = " << a << " b = " << b << endl;
    // swapInt(a, b);
    // mySwap(a, b);  // 自动类型转换
    mySwap<int>(a, b); // 显式指定类型
    cout<< "交换后: " << endl;
    cout<< "a = " << a << " b = " << b <<endl;
    cout << endl;
    double c = 1.1;
    double d = 2.2;
    cout << "交换前: " << endl;
    cout << "c = " << c << " d = " << d << endl;
    // swapDouble(c, d);
    mySwap(c, d); // 自动类型转换
    cout << "交换后: " << endl;
    cout << "c = " << c << " d = " << d << endl;
};

int main(){

    test01();

    return 0;
}