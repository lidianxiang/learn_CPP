#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*

函数原型：  
    count(iterator_beg, iterator_end, value)  // 统计元素出现的次数

*/

// 统计内置数据类型
void test01(){

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);

    int num = count(v.begin(), v.end(), 20);
    cout << "元素20的个数: " << num << endl;
}

class Person{
public:
    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    // 重载operator==运算符
    bool operator==(const Person &p){
        if (this->m_Age == p.m_Age){
            return true;
        }
        else{
            return false;
        }
    }

    string m_Name;
    int m_Age;

};


// 统计内置数据类型
void test02(){
    vector<Person> v;
    // 创建对象
    Person p1("刘备", 35);
    Person p2("关羽", 35);
    Person p3("张飞", 35);
    Person p4("赵云", 30);
    Person p5("曹操", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    Person pp("诸葛亮", 35);

    int num = count(v.begin(), v.end(), pp);
    cout << "和诸葛亮同岁的人一共有: " << num << "个人" << endl;

}

int main(){

    test01();

    test02();

    return 0;
}