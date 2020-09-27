#include<iostream>
using namespace std;
#include<set>

/*

set基本概念： 所有元素都会在插入时自动被排序
其本质：set/multiset属于关联式容器，底层结构是用二叉树实现的

set/multiset区别：
    set不允许容器中有重复的元素
    multiset允许容器中有重复的元素

构造：
    1、set<T> st;   // 默认构造函数
    2、set(const set &st);  // 拷贝构造函数

赋值：
    set& operator=(const set &st);

*/

void printSet(set<int> &s){
    for(set<int>::iterator it=s.begin(); it!=s.end(); it++){
        cout << *it << " ";
    }   
    cout << endl;
}


void test01(){
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(50);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    printSet(s1);   // set容器不允许插入重复的值，且输出是升序排序的序列

    // 拷贝构造
    set<int> s2(s1);
    printSet(s2);

    // 赋值
    set<int> s3;
    s3 = s1;
    printSet(s3);
}

int main(){

    test01();

    return 0;
}
