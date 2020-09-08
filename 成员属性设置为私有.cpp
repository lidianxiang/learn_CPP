#include<iostream>
using namespace std;

// 将成员属性设置为私有的优点
// 1、自己可以控制读写权限
// 2、对于写权限，可以检测数据的有效性
class Person{
private:
    // 姓名
    string m_Name;
    // 年龄
    int m_Age;
    // 情人
    string m_Lover;

public:
    // 姓名设置为可读可写
    void setName(string name){
        m_Name = name;  // 设置姓名
    }

    string getName(){
        return m_Name;  // 获取姓名
    }

    int getAge(){
        m_Age = 0;
        return m_Age;
    };

    void setLover(string lover){
        m_Lover = lover;
    };
};


int main(){
    Person p;
    p.setName("张三");
    p.setLover("李四");
    cout << "姓名: " << p.getName() << endl;
    cout << "年龄: " << p.getAge() << endl;
}