#include<iostream>
using namespace std;


class Person{
public:

    // 无参构造函数
    Person(){
        cout << "Person 无参构造函数的调用" << endl;
    };
    
    // 有参构造函数
    Person(int a){
        age = a;
        cout << "Person 有参构造函数的调用" << endl;
    };

    // 拷贝构造函数
    Person(const Person &p){
        age = p.age;
        cout << "Person 拷贝构造函数的调用" << endl;
    };

    // 析构函数
    ~Person(){
        cout << "Person 析构函数的的调用" << endl;
    };

    int age;
};


void test01(){
    // 1、括号法调用
    // Person p;  // 默认构造函数的调用,注意调用默认构造函数的时候，不要加小括号()
    // Person p2(10);
    // Person p3(p2);

    // 2、显示法
    Person p;
    Person p2 = Person(10);
    Person p3 = Person(p2);

    // 3、隐式转换法
    Person p4 = 10; // 有参构造， 相当于 Person p4 = Person(10)
    Person p5 = p4; // 拷贝构造
};


int main(){
    
    test01();

    return 0;
}