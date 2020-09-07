#include<iostream>
using namespace std;

// 类似函数的申明， 让第15行的代码（Building * building;）正常运行，详细信息后续再来写
class Building;

class GoodGay{

public:

    void visit();

    GoodGay();

    Building * building;
};

class Building{

public:
    friend class GoodGay;
    Building();

public:
    string m_SittingRoom;  // 客厅

private:
    string m_BeddingRoom;  // 卧室

};

// 类外进行函数的初始化（构造函数），需要加上作用域
Building::Building(){
    m_SittingRoom = "客厅";
    m_BeddingRoom = "卧室";
};

GoodGay::GoodGay(){
    // 创建Building对象
    building = new Building;
};

void GoodGay::visit(){
    cout << "好基友类正在访问: " << building->m_SittingRoom << endl;
    cout << "好基友类正在访问: " << building->m_BeddingRoom << endl;
};

void test01(){

    GoodGay gg;
    gg.visit();
};

int main(){

    test01();

    return 0;
}