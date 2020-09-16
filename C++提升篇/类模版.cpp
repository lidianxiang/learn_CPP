#include<iostream>
using namespace std;

/*

类模版的作用： 建立一个通用类，类中的成员、数据类型可以不具体指定，用一个虚拟的类型指定

语法:
    template<typename T>
    类

*/

template<class NameType, class AgeType>
class Person{
public:
    // 构造函数
    Person(NameType name, AgeType age){
        this->m_Name = name;
        this->m_Age = age;
    };

    NameType m_Name;
    AgeType m_Age;
};

void test01(){
    Person<string, int> p1("孙悟空" ,18);
    cout << "p1: name: " << p1.m_Name << " age: " << p1.m_Age << endl;
    Person<string, double> p2("猪八戒", 22.4);
    cout << "p2: name: " << p2.m_Name << " age: " << p2.m_Age << endl;
};


int main(){

    test01();

    return 0;
}