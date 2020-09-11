#include<iostream>
using namespace std;

/*

函数调用运算符重载
    函数调用运算符()也可以重载
    由于重载后使用的方法非常像函数的调用，因此称为仿函数
    仿函数没有固定的写法，非常灵活

*/

class MyPrint{

public:

    void operator()(string test){
        cout << test << endl;
    };
};

void MyPrint02(string test){
        cout << test << endl;
};

void test01(){
    MyPrint myPrint;
    myPrint("hello, world"); // 重载函数调用函数，被称为仿函数
    MyPrint02("hello, world");
};

class MyAdd{
public:
    int operator()(int num1, int num2){
        return num1 + num2;
    };
};

void test02(){
    MyAdd myAdd;
    int res = myAdd(1, 2);
    cout << "res = " << res << endl;

    // 匿名函数对象
    cout << MyAdd()(1, 2) << endl;
};


int main(){

    test01();

    test02();

    return 0;
}