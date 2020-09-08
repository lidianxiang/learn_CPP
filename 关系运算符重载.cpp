#include<iostream>
using namespace std;


class Person{
public:
    string m_Name;
    int m_Age;

    Person(string name, int age){
        m_Name = name;
        m_Age = age;
    };

    // 重载关系运算符
    bool operator==(Person &p){
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age){
            return true;
        };
        return false;
    };

};

void test01(){
    Person p1("Tom", 18);
    Person p2("Harry", 18);

    if (p1 == p2){
        cout << "p1和p2是相等的" << endl;
    }
    else{
        cout << "p1和p2是不相等的" << endl;
    }
};

int main(){
    
    test01();

    return 0;
}