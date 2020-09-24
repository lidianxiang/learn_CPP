#include<iostream>
using namespace std;
#include<list>

/*

功能：将数据进行链式存储
链表(list)是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针来实现的

链表的组成：链表是一系列节点组成的， 一个是存储数据元素的数据域，另一个是存储下一个节点地址的指针域

STL中的链表是一个双向循环链表

函数原型：
    1、list<T> lst;
    2、list(beg, end);
    3、list(n, elem);
    4、list(const list &lst);

*/

void printList(const list<int> &L){
    for(list<int>::const_iterator it=L.begin(); it != L.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

}


void test01(){
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    printList(L1);

    // 区间构造
    list<int> L2(L1.begin(), L1.end());
    printList(L2);

    // 拷贝构造
    list<int> L3(L2);
    printList(L3);

    // n个elem
    list<int> L4(10, 100);
    printList(L4);

}


int main(){

    test01();

    return 0;
}