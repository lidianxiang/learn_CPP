#include<iostream>
using namespace std;
#include<deque>

/*

函数原型：
    1、deque.empty();           // 判断容器是否为空
    2、deque.size();            // 返回容器中元素的个数
    3、deque.resize(num);       // 重新指定容器的长度为num，若容器变长，则以默认值填充新的位置
                                  如果容器变短，则末尾超出的长度的元素被舍弃
    4、deque.resize(num, elem);   // 重新指定容器的长度为num，若容器变长，则以elem填充新的位置
                                     如果容器变短，则末尾超出的长度的元素被舍弃

*/

void printDeque(const deque<int> d){
    for(deque<int>::const_iterator it=d.begin(); it!= d.end(); it++){
        cout << *it << "  ";
    }
    cout << endl;

};

void emptyDeque(deque<int> q){
    if (q.empty()){
        cout << "容器为空" << endl;
    }
    else{
        cout << "容器不为空" << endl;
    }
}


void test01(){

    deque<int> d1;
    for(int i=0; i<10; i++){
        d1.push_front(i);
    }
    printDeque(d1);
    emptyDeque(d1);

    deque<int> d2 = d1;
    d2.resize(20);
    printDeque(d2);

    deque<int> d3 = d1;
    d3.resize(4);
    printDeque(d3);
};


int main(){

    test01();

    return 0;
}