#include <iostream>
using namespace std;
#include <string>

struct student
{
    string name;
    int age;
    float score;
};

int main()
{
    struct student s1 = {"张三", 18, 77.5};
    // 结构体指针
    struct student *p = &s1;
    // 结构体指针通过 `->` 来访问结构体的属性
    cout << "姓名: " << p->name << " 年龄: " << p->age << " 分数: " << p->score << endl;
    return 0;
}