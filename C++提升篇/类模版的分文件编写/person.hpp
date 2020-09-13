#include <iostream>
using namespace std;

template <class T1, class T2>
class Person
{
public:
    T1 m_Name;
    T2 m_Age;
    // 类内声明
    Person(T1 name, T2 age);
    // 类内声明
    void showPerson();
};

// 构造函数的类外实现
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_Name = name;
    this->m_Age = age;
};

// 成员函数的类外实现
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "姓名: " << this->m_Name << " 年龄: " << this->m_Age << endl;
};

