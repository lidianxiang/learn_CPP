#include<fstream>
#include<iostream>
using namespace std;

class Person{
public:
    char m_Name[64];
    int m_Age;
    // char m_Name[64];
};

void test01(){

    // 创建流对象
    ifstream ifs;
    // 打开文件
    ifs.open("person.txt", ios::in | ios::binary);
    if (!ifs.is_open()){
        cout << "文件打开失败" << endl;
        return;
    };

    // 读数据
    Person p;
    ifs.read((char *)&p, sizeof(Person));

    cout << "姓名: " << p.m_Name << " 年龄: " << p.m_Age << endl;

    ifs.close();


};

int main(){

    test01();

    return 0;
}