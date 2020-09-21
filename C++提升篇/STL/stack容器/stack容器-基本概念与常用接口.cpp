#include<iostream>
using namespace std;
#include<stack>

/*
基本概念：一种数据结构，特点是先进后出。

数据进入栈中的过程称为：入栈 push
数据弹出栈中的过程称为：出栈 pop

常用接口：
    1、构造函数： 
        1.1 stack<T> stk;
        1.2 stack(const stack &stk);
    2、赋值操作
        2.1 stack& operator=(const stack &stk);
    3、数据存取
        3.1 push(elem);
        3.2 pop();
        3.3 top();
    4、大小操作
        4.1 empty();
        4.2 size();

*/

void test01(){

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // 只要栈不为空，查看栈顶，并执行出栈操作
    while(!s.empty()){
        // 查看栈顶元素
        cout << "栈顶元素: " << s.top() << endl;
        // 出栈
        s.pop();
    }

    cout << "栈的大小: " << s.size() << endl;


}


int main(){

    test01();

    return 0;
}