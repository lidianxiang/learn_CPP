#include<iostream>
using namespace std;

/* 类在设计时，可以把属性和行为放在不同的权限下，加以控制
   访问权限有三种： 
        公共权限public: 类内可以访问， 类外可以访问 
        保护权限protected 类内可以访问， 类外不可以访问
        私有权限private 类内可以访问， 类外不可以访问

*/

class Person{

public:
    string m_Name;

protected:
    string m_Car;

private:
    int m_Password;

public:
    void func(){
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;
    }
};

int main(){

    Person p1;
    p1.m_Name = "李四";
    // p1.m_Car = "奔驰";  // 保护权限的内容是不可以修改
    // p1.m_Password = 123654;  // 私有权限的内容是不可以修改的

    return 0;
}