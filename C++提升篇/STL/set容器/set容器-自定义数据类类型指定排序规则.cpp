#include<iostream>
using namespace std;
#include<set>

class Person{

public:
    string m_Name;
    int m_Age;

    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }
};

// 仿函数的本质是重载operator()操作运算符
class comparePerson{
public: 
    bool operator()(const Person &p1, const Person &p2){
        return p1.m_Age > p2.m_Age;
    }
};

void test01(){

    // 自定义数据类型，通常都会指定排序规则
    set<Person, comparePerson> s;

    // 创建Person对象
    Person p1("刘备", 25);
    Person p2("关羽", 28);
    Person p3("张飞", 26);
    Person p4("赵云", 21);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for(set<Person, comparePerson>::iterator it=s.begin(); it!= s.end(); it++){
        cout << "姓名: " << it->m_Name << " 年龄: " << it->m_Age << endl;
    }

}


int main(){

    test01();

    return 0;
}