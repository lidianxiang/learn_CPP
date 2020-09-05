#include<iostream>
using namespace std;

/*
    每一个非静态成员函数只会诞生一个函数实例，也就说多个同类型的对象会共用一块代码
    那么问题是：这一块代码是如何区分哪个对象是在调用自己呢？
答案：
    c++通过提供特殊的对象指针，this指针解决上述问题，this指针指向被调用函数的成员函数所属的对象
    this指针是隐含每一个非静态成员函数内的一种指针
    this指针不需要定义，直接使用即可
this指针的用途：
    当形参和成员变量同名时，可用this指针来区分
    当类的非静态成员函数中返回对象本身，可使用 return *this
*/

class Person{
public:

    Person(int age){
        // this指针指向被调用函数的成员函数所属的对象
        this->age = age;
    };

    int age;

    void PersonAddAge(Person &p){
        this->age += p.age;
    };

    Person& PersonAddAge2(Person &p){
        this->age += p.age;
        // this指向p2的指针，而*this指向的是p2这个对象本体
        return *this;
    };
};

void test01(){

    Person p1(18);
    cout << "p1的年龄: " << p1.age << endl;
};

void test02(){
    Person p1(10);
    Person p2(18);

    // p2.PersonAddAge(p1);
    // cout << "p2的年龄为: " << p2.age << endl;
    // 链式编程对象
    p2.PersonAddAge2(p1).PersonAddAge2(p1).PersonAddAge2(p1);
    cout << "p2的年龄为: " << p2.age << endl;
};

int main(){

    test01();
    test02();

    return 0;
}