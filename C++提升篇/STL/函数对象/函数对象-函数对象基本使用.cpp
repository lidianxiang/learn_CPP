#include<iostream>
using namespace std;


/*

概念：
    1、重载函数对象操作符的类，其对象常称为函数对象
    2、函数对象使用重载()时，行为类似函数调用，也叫仿函数
本质：
    函数对象(仿函数)是一个类，不是一个函数

函数对象使用：
特点：  
    1、函数对象在使用时，可以像普通函数那样调用，可以有返回值；
    2、函数对象超出普通函数的概念，函数对象可以有自己的状态；
    3、函数对象可以作为参数传递；

*/

class MyAdd{
public: 
    int operator()(int v1, int v2){
        return v1 + v2;
    }
};

// 函数对象超出普通函数的概念，函数对象可以有自己的状态；
class MyPrint{

public:

    MyPrint(){
        this->count = 0;
    }

    void operator()(string test){
        cout << test << endl;
        count++;
    }

    int count;
};

// 函数对象可以作为参数进行传递
void doPrint(MyPrint &mp, string test){
    mp(test);
}

void test01(){
    MyAdd myadd;
    cout << myadd(10, 10) << endl;
}

void test02(){
    MyPrint myprint;
    myprint("hello, world!");
    myprint("hello, world!");
    myprint("hello, world!");
    myprint("hello, world!");

    cout << "myprint调用次数为: " << myprint.count << endl;
}

void test03(){
    MyPrint myprint;
    doPrint(myprint, "hello, C++");
}

int main(){

    // test01();
    // test02();

    test03();

    return 0;
}