#include<iostream>
using namespace std;

/*

调用规则如下：
    1、如果函数模版和普通函数都可以实现，优先调用普通函数
    2、可以通过空模版参数列表来强制调用函数模版
    3、函数模版也可以发生函数重载
    4、如果函数模版可以产生更好的匹配，优先调用函数模版

*/

void myPrint(int a, int b){
    cout << "调用的普通函数" << endl;
};

template<class T>
void myPrint(T a, T b){
    cout << "调用的模板函数" << endl;
};

template<class T>
void myPrint(T a, T b, T c){
    cout << "调用重载的模板函数" << endl;
};

void test01(){
    int a = 1;
    int b = 2;
    int c = 3;
    myPrint(a, b); // 优先调用普通函数
    // 通过空模版来优先调用模版函数
    myPrint<>(a, b);

    myPrint(a, b, c); // 模板函数也可以发生重载

    char e = 'a';
    char f = 'b';
    myPrint(e, f); // 如果函数模版可以产生更好的匹配，优先调用函数模版
};

int main(){
    test01();

    return 0;
}