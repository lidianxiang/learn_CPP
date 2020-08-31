#include<iostream>
using namespace std;


int main(){
    short num1 = 10;
    int num2 = 10;
    long num3 = 10;
    long long num4 = 10;

    cout << "num1 = " << num1 << endl;
    cout << "num1 所占用的空间为：" << sizeof(num1) << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num2 所占用的空间为：" << sizeof(num2) << endl;
    cout << "num3 = " << num3 << endl;
    cout << "num3 所占用的空间为：" << sizeof(num3) << endl;
    cout << "num4 = " << num4 << endl;
    cout << "num4 所占用的空间为：" << sizeof(num4) << endl;

    return 0;
}
