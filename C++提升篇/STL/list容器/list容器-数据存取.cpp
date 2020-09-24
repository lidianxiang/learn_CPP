#include<iostream>
using namespace std;
#include<list>


void test01(){

    list<int> L;

    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    L.push_back(40);

    // 不可以使用[]和at()函数的形式来访问list容器中的元素
    // 原因是list本质是链表，不是用连续线性空间存储数据

    cout << "第一个元素: " << L.front() << endl;
    cout << "最后一个元素: " << L.back() << endl;


}


int main(){

    test01();

    return 0;
}