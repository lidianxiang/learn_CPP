#include<iostream>
using namespace std;


int main(){

    int a = 10;
    // 引用的作用是给变量其别名
    int &b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}