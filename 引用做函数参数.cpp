#include<iostream>
using namespace std;

// 值传递
void mySwap01(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

// 地址传递
void mySwap02(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 引用传递， 引用的本质是指针常量，要明白引用就需要理解指针常量
void mySwap03(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


int main(){

    int a = 10;
    int b = 20;

    mySwap01(a, b);
    cout <<  "使用mySwap01函数后: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // mySwap02(&a, &b);
    // cout << "使用mySwap02函数后: " << endl;
    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;

    mySwap03(a, b);
    cout << "使用mySwap03函数后: " << endl;
    // 引用和指针一样，形参是会修饰实参的
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;

}