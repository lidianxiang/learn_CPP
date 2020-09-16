#include<iostream>
using namespace std;

/*

全局函数的类内实现： 直接在类内声明友元即可
全局函数的类外实现： 需要提前让编译器知道全局函数的存在

*/
template<class T1, class T2>
class Person;

template <class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
    cout << "类外实现的 --- 姓名: " << p.m_Name << " 年龄: " << p.m_Age << endl;
};

template<class T1, class T2>
class Person{
    // 全局函数 类内实现
    friend void printPerson(Person<T1, T2> p){
        cout << "姓名: "<< p.m_Name << " 年龄: " << p.m_Age << endl;
    };
    //类内声明，类外实现
    // 需要添加一个空模版，让编译器知道这是个模版的友元的定义
    friend void printPerson2<>(Person<T1, T2> p);
    
public:
    Person(T1 name, T2 age){
        this->m_Name = name;
        this->m_Age = age;
    };
private:
    T1 m_Name;
    T2 m_Age;
};

// 全局函数类内实现
void test01(){
    Person<string, int> p("Tom", 18);
    printPerson(p);
};

void test02(){
    Person<string, int> p("Jerry", 30);
    printPerson2(p);
};

int main(){

    // test01();
    test02();
    
    return 0;
}