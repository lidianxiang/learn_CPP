#include <iostream>
using namespace std;

/*

多态分为两类：
    1、静态多态： 函数重载和运算符重载属于静态多态，复用函数名
    2、多态多态： 派生类和虚函数实现运行时多态

静态多态和多态多态的区别：
    1、静态多态的函数地址早绑定 - 编译阶段确定函数地址
    2、动态多态的函数地址晚绑定 - 运行阶段确定函数地址

*/

// 动物类
class Animal
{
public:
    // 加上virtual后，地址就会晚绑定，在运行阶段确定函数地址
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class Cat : public Animal
{
public:
    // 重写，函数返回值类型、函数名、参数列表完全相同
    virtual void speak()
    {
        cout << "小猫在说话" << endl;
    };
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "小狗在说话" << endl;
    };
};

void doSpeak(Animal &animal)
{
    // 地址早绑定，所以输出的是父类的speak函数
    animal.speak();
};

void test01()
{
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
};

void test02(){
    cout << "sizeof Animal = " <<  sizeof(Animal) << endl;
};


int main()
{

    // test01();
    test02();
    return 0;
}