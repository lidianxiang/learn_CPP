#include<iostream>
using namespace std;
#include<vector>

//自定义一个Person类的数据
class Person{
public:
    int m_Age;
    string m_Name;

    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    };
};


void test01(){
    vector<Person> v;

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    // 向容器汇中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for(vector<Person>::iterator it=v.begin(); it != v.end(); it++){
        // cout << "姓名: " << (*it).m_Name << "  年龄: " << (*it).m_Age << endl;
        cout << "姓名: " << it->m_Name << "  年龄: " << it->m_Age << endl;
    };
};

// 存放自定义数据的指针
void test02(){
    vector<Person*> v;

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    // 向容器汇中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for(vector<Person*>::iterator it=v.begin(); it != v.end(); it++){
        // cout << "姓名: " << (*it)->m_Name << "  年龄: " << (*it)->m_Age << endl;
        cout << "姓名: " << (*(*it)).m_Name << "  年龄: " << (*(*it)).m_Age << endl;
    };
};

int main(){

    // test01();
    test02();

    return 0;
}