#include<algorithm>
#include<iostream>
using namespace std;
#include<vector>

/*

常用的查找算法：
    1、find            // 查找元素
    2、find_if         // 按条件查找元素
    3、adjacent_find   // 查找相邻重复元素
    4、binary_search   // 二分查找法
    5、count           // 统计元素个数
    6、count_if        // 按条件统计元素个数


find 函数原型: 查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
    find(iterator_beg, iterator_end, value);

*/


void test01(){

    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }

    vector<int>::iterator it = find(v.begin(), v.end(), 5);

    if (it == v.end()){
        cout << "没有这个元素";
    }
    else{
        cout << "查到了: " << *it << endl;
    }
}

class Person{

public:
    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }
    // 对于自定义的类型，需要重载operator==, 这样find才会知道如何对比Person数据类型
    bool operator==(const Person &p){
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age){
            return true;
        }
        else
        {
            return false;
        }
        
    }

    string m_Name;
    int m_Age;
};

void test02(){

    vector<Person> v;

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    // 要查找元素
    Person pp("bbb", 20);

    vector<Person>::iterator it = find(v.begin(), v.end(), pp);

    if (it == v.end()){
        cout << "查无此人" << endl;
    }
    else
    {
        cout << "找到了 姓名: " << it->m_Name << " 年龄: " << it->m_Age << endl;
    }
    

}


int main(){

    // test01();

    test02();

    return 0;
}