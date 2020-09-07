#include<iostream>
using namespace std;

class Building;

class GoodGay{
public:

    GoodGay();

    void visit(); // 让visit函数可以访问Building类中的私有成员
    void visit2(); // 让visit2函数不可以访问Building类中的私有成员

    Building * building;
};

class Building{

public:
    Building();
    friend void GoodGay::visit();

public:
    string m_SittingRoom;

private:
    string m_BeddingRoom;

};

Building::Building(){
    m_SittingRoom = "客厅";
    m_BeddingRoom = "卧室";
};

GoodGay::GoodGay(){
    building = new Building;

};

void GoodGay::visit(){
    cout << "visit 函数正在访问: " << building->m_SittingRoom << endl;
    cout << "visit 函数正在访问: " << building->m_BeddingRoom << endl;
};

void GoodGay::visit2()
{
    cout << "visit2 函数正在访问: " << building->m_SittingRoom << endl;
    // cout << "visit2 函数正在访问: " << building->m_BeddingRoom << endl;
};

void test01(){
    GoodGay gg;
    gg.visit();
    gg.visit2();
}

int main(){

    test01();

    return 0;
}