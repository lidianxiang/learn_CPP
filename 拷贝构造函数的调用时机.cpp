#include<iostream>
using namespace std;


/*

C++拷贝构造函数调用时机通常有3种情况
1、使用一个已经创建完毕的对象来初始化一个新对象
2、值传递的方式来给函数参数传值
3、以值方式返回局部对象 

*/

class Person{
public:

    Person(){
        cout << "无参构造函数" << endl;
        mAge= 0;
    };

    ~Person(){
        cout << "析构函数的调用" << endl;
    };

    Person(int age){
        cout << "有参构造函数" << endl;
        mAge = age;
    };

    Person(const Person & p){
        mAge = p.mAge;        
        cout << "拷贝构造函数" << endl;
    };

    int mAge;
};

void test01(){
    Person p1(10);
    // 使用一个已经创建完毕的对象来初始化一个新对象
    Person p2(p1);
    cout << "p2的年龄: " << p2.mAge << endl;
};

void doWork(Person p){

};

// 值传递的方式来给函数参数传值, 会调用拷贝函数
void test02(){
    Person p;
    doWork(p);
};

Person doWork2(){
    Person p1;
    cout << &p1 << endl;
    return p1;
};

void test03(){

    Person p = doWork2();
    cout << &p << endl;
    
};


int main(){

    // test01();
    // test02();
    test03();

    return 0;
}