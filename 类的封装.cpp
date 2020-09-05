#include<iostream>
using namespace std; 

// 圆周率
const double PI = 3.14;

class Circle{
    // 访问权限

public:
    // 属性
    // 半径
    int m_r;
    // 行为
    double calculateZC(){
        return 2 * PI * m_r;
    }
};


int main(){

    // 创建类的对象
    Circle c1;
    // 给对象的属性进行赋值
    c1.m_r = 10;
    cout << "圆的周长为: " << c1.calculateZC() << endl;

    return 0;
}