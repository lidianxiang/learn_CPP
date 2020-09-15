#include<iostream>
using namespace std;

/*

多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时，无法调用到子类的析构代码
解决办法： 将父类中的析构函数改为虚析构或者纯虚析构

虚析构或纯虚析构共性：
    1、可以解决父类指针释放子类对象
    2、都需要有具体的函数实现

虚析构或纯虚析构区别：
    1、如果是纯虚析构，该类属于抽象类，无法实例化对象
*/

class Animal{
public:

    Animal(){
        cout<< "Animal的构造函数调用" << endl;
    };

    virtual void speak() = 0;

    // ~Animal(){
    // virtual ~Animal(){  // 利用虚析构可以解决父类指针释放子类对象时不干净的问题
    //     cout << "Animal的析构函数调用" << endl;
    // };

    // 纯虚析构也可以做到上述的问题
    virtual ~Animal() = 0; // 这个只是声明
};

// 纯虚析构的具体实现
Animal::~Animal(){
    cout << "Animal的纯虚析构函数调用" << endl;
};

class Cat: public Animal{
public:
    string *m_Name;

    Cat(string name){
        cout << "Cat的构造函数调用" << endl;
        m_Name = new string(name);
    };

    virtual void speak(){
        cout << *m_Name << "小猫在说话..." << endl;
    };
    
    ~Cat(){
        if (m_Name != NULL){
            cout << "Cat析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        };
    };

};

void test01(){
    Animal * animal = new Cat("Tom");
    animal->speak();
    // 父类指针在析构时，不会调用子类中的析构函数，导致子类如果有堆区属性，会出现内存泄漏
    delete animal;
};

int main(){

    test01();
    return 0;
}