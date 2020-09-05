#include<iostream>
using namespace std;

// class的默认权限是私有权限
class C1{
    int m_A;
};

// struct的默认权限是公共权限
struct C2{
    int m_A;
};


int main(){
    C1 c1;
    // c1.m_A = 100;  // 错误的，无法访问
    C2 c2;
    c2.m_A = 100;
    return 0;
}