#include<iostream>
using namespace std;
# include<string>

struct student {
    string name; 
    int age;
    float score;
};


int main(){
    struct student s1  = {"张三", 18, 77.5};
    cout << "姓名: " << s1.name << " 年龄: " << s1.age << " 分数: " <<s1.score << endl;
    return 0;
}