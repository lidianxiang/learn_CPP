#include<iostream>
using namespace std;

/*

c++编译器至少给一个类添加4个函数
    1、默认构造函数(无参，函数体为空)
    2、默认析构函数（无参，函数体为空）
    3、默认拷贝构造函数，对属性进行值拷贝
    4、赋值运算符 operator=， 对属性进行值拷贝

tip: 如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝的问题

*/

class Person{
public:

    int *m_Age;

    // 构造函数
    Person(int age){
        m_Age = new int (age);
    };

    // 析构函数
    ~Person(){
        if (m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }
    };

    Person& operator=(Person &p){

        // 先判断属性是否已经赋值了，如果有，则先释放掉其所在堆区的数据地址
        if (m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        };

        // 深拷贝
        m_Age = new int(*p.m_Age);
        return *this;

    };
};

void test01(){

    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1;
    cout << "p1的年龄: " << *p1.m_Age << endl;
    cout << "p2的年龄: " << *p2.m_Age << endl;
    cout << "p3的年龄: " << *p3.m_Age << endl;
};


int main(){

    test01();

    return 0;
}