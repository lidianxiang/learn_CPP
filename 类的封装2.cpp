#include<iostream>
using namespace std;


// 设计一个学生类，属性有姓名和学号
// 可以给姓名和学号赋值， 可以显示学生的姓名和学号
class Student{
public:
    
    string m_name; // 姓名
    int m_id;  // 学号

    void setName(string name){
        m_name = name;
    }
    void setID(int id){
        m_id = id;
    }
    void showStudent(){
        cout << "姓名: " << m_name << "\t" << "学号: " << m_id << endl;
    }
};

int main(){

    // 实例化一个对象
    Student s1;
    // 给s1对象进行属性赋值
    // s1.m_name = "张三";
    s1.setName("张三");
    // s1.m_id = 1;
    s1.setID(1);
    s1.showStudent();
    return 0;
}