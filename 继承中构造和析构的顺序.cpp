#include<iostream>
using namespace std;

/*

继承中子类和父类的构造和析构顺序为：
    1、父类的构造函数
    2、子类的构造函数
    3、子类的析构函数
    4、父类的析构函数

*/

class Base{
public:
    Base(){
        cout << "Base构造函数！" << endl;
    };

    ~Base(){
        cout << "Base析构函数！" << endl;
    };
};

class Son: public Base{

public:
    Son(){
        cout << "Son构造函数!" << endl;
    };

    ~Son(){
        cout << "Son析构函数!" << endl;
    };

};

void test01(){
    Son son;
};


int main(){

    test01();

    return 0;
}