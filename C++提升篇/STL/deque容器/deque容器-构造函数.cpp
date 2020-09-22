#include<iostream>
using namespace std;
#include<deque>

/*

功能：双端数组，可以对头端进行插入删除操作

deque与vector区别： 
    1、vector对于头部的插入删除效率低，数据量越大，效率越低
    2、deque相对而言，对头部的插入删除速度比vector快
    3、vector访问元素的速度会比deque快，这和两者的内部实现有直接关系

deque的内部原理：
    deque内部有个中控器，维护每段缓冲区的内容，缓冲区中存放真实的数据，中控器维护的是每个缓冲区的地址，使得使用deque
的时候像一片连续的内存空间。

函数原型：
    1、deque<T> deqT;         // 默认构造函数
    2、deque(beg, end);       // 构造函数将[beg, end]区间中的元素拷贝给本身
    3、deque(n, elem);        // 构造函数将n个elem拷贝本身
    4、deque(const deque &deq);  // 拷贝构造函数

*/

void printDeque(const deque<int> d){
    // 加上const，迭代器换成const_iterator，使得变成只读状态，不能修改
    for(deque<int>::const_iterator it=d.begin(); it != d.end(); it++){
        // it = 100;
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    deque<int> d1;
    for(int i=0; i<10; i++){
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);

    deque<int> d3(10, 100);
    printDeque(d3);

    deque<int> d4(d3);
    printDeque(d4);
}


int main(){

    test01();

    return 0;
}