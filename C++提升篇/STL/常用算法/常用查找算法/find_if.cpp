#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*

函数原型：  
    find_if(iterator_beg, iterator_end, _Pred)
其中，_Pred表示函数或者谓词（返回bool类型的仿函数）

*/

class GreaterFive{
public:
    bool operator()(int val){
        return val > 5;
    }

};

void test01(){

    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }

    vector<int>::iterator it=find_if(v.begin(), v.end(), GreaterFive());
    if(it == v.end()){
        cout << "没有这个数" << endl;
    }
    else
    {
        cout << "查到了这个数: " << *it << endl;
    }
}

class Person{
public:

    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class Greater20{
public:
    bool operator()(Person &p){
        return p.m_Age > 20;
    }
};

void test02(){

    vector<Person> v;

    Person p1("aaa", 10);
    Person p2("bbb" ,20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator it=find_if(v.begin(), v.end(), Greater20());

    if (it == v.end()){
        cout << "没有找到这个元素" << endl;
    }
    else
    {
        cout << "找到了这个元素 姓名: "<< it->m_Name << " 年龄: " << it->m_Age << endl;
    }
    

}


int main(){

    // test01();

    test02();

    return 0;
}