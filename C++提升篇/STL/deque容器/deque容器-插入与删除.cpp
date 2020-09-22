#include<iostream>
using namespace std;
#include<deque>

/*

函数原型：
一、两端插入操作
    1.1、push_back(elem);     // 在容器尾部添加一个数据
    1.2、push_front(elem);    // 在容器头部插入一个数据
    1.3、pop_back();          // 删除容器最后一个数据 
    1.4、pop_front();         // 删除容器第一个数据

二、指定位置操作
    2.1、insert(pos, elem);      // 在pos位置插入一个elem元素的拷贝，返回新的数据的位置
    2.2、insert(pos, n, elem);   // 在pos位置插入n个elem的数据，无返回值
    2.3、insert(pos, beg, end);  // 在pos位置插入[beg, end]区间的数据，无返回值
    2.4 clear();                 // 清空容器的所有数据
    2.5、erase(beg, end);        // 删除[beg, end]区间的数据，返回下一个数据的位置
    2.6、erase(pos);             // 删除pos位置的数据，返回下一个数据的位置

*/

void printDeque(const deque<int> d){
    for (deque<int>::const_iterator it = d.begin(); it!= d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
}

void test01(){

    deque<int> d1;
    // 头插
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    // 尾插
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
    printDeque(d1);

    d1.pop_back();
    d1.pop_front();
    printDeque(d1);

    // 插入
    d1.insert(d1.begin(), 1000);
    printDeque(d1);

    d1.insert(d1.end(), 2, 15);
    printDeque(d1);

    // 按照区间进行插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);

    // 删除
    d1.erase(d1.begin());
    printDeque(d1);

    d2.clear();
    printDeque(d2);

}


int main(){

    test01();

    return 0;
}