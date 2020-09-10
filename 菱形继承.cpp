#include<iostream>
using namespace std;

/*

菱形继承：
    1、两个派生类继承同一个基类
    2、又有某个类同时继承这两个派生类
    3、这种继承被称为菱形继承，或者钻石继承
解决菱形继承的方法：
    利用virtual（虚继承）的方式

*/

// 动物类
class Animal{
public:
    int m_Age;
};

// 羊类
// 虚基类
class Sheep: virtual public Animal {};

// 骆驼类
class Camel: virtual public Animal{};

// 羊驼类
class Sheep_Camel: public Sheep, public Camel{};

void test01(){
    Sheep_Camel sc;
    sc.Sheep::m_Age = 100;
    sc.Camel::m_Age = 200;
    // 当菱形继承时，两个父类拥有相同的数据，需要加上作用域来区分
    cout << "sc.Sheep::m_Age = " << sc.Sheep::m_Age << endl; // 200
    // 以最后一个赋值为准
    cout << "sc.Camel::m_Age = " << sc.Camel::m_Age << endl; // 200
    cout << "sc.m_Age = " << sc.m_Age << endl;

};

int main(){

    test01();

    return 0;
}