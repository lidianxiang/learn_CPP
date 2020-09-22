#include<iostream>
using namespace std;
#include<deque>

/*

函数原型：
    1、deque& operator=(const deque &deq);    // 重载赋值操作符
    2、assign(beg, end);                      // 将[beg, end]区间中的数据拷贝赋值给本身
    3、assign(n, elem);                       // 将n个elem拷贝赋值给本身

*/

void printDeque(const deque<int> d){
    for(deque<int>::const_iterator it=d.begin(); it!=d.end(); it++){
        cout << *it << "  "; 
    }
    cout << endl;
}

void test01(){

    deque<int> d1;
    for(int i=0; i<10; i++){
        d1.push_front(i);
        d1.push_back(i);
    }

    printDeque(d1);

    deque<int> d2 = d1;
    printDeque(d2);

    deque<int> d3;
    d3.assign(d2.begin()+1, d2.end()-1);
    printDeque(d3);

    deque<int> d4;
    d4.assign(10, 100);
    printDeque(d4);

}


int main(){

    test01();

    return 0;
}