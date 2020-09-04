#include <iostream>
using namespace std;
#include <string>

struct student
{
    string name;
    int age;
    float score;
};

struct teacher{
    int id;
    string name;
    int age;
    struct student stu;
};


int main()
{
    struct teacher teacher1 = {10000, "王老师" , 35, {"李四", 15, 70}};
    cout << "姓名: " << teacher1.name << " 年龄: " << teacher1.age
         << " id: " << teacher1.id <<  " 学生的姓名: " << teacher1.stu.name 
         << endl;
    return 0;
}