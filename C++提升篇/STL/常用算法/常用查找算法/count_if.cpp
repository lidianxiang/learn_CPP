#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*

函数原型：
    count_if(iterator_beg, iterator_end, _Pred)    // 按条件统计元素出现的个数

*/

class Greater4{
public:
    bool operator()(int val){
        return val > 4;
    }
};

// 统计内置的数据类型
void test01(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    int num = count_if(v.begin(), v.end(), Greater4());
    cout << "大于4的个数为: " << num << endl;

}

class Person{
public:
    string m_Name;
    int m_Age;

    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }
};


class AgeGreater30{
public:
    bool operator()(const Person &p){
        return p.m_Age > 30;
    }
};

// 统计自定义的数据类型
void test02(){
    vector<Person> v;

    // 创建对象
    Person p1("刘备", 35);
    Person p2("关羽", 35);
    Person p3("张飞", 35);
    Person p4("赵云", 30);
    Person p5("曹操", 20);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    int num = count_if(v.begin(), v.end(), AgeGreater30());
    cout << "年龄大于30岁的人一共有: " << num << "个" << endl;
}


int main(){

    // test01();
    test02();

    return 0;
}