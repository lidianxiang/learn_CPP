#include<iostream>
using namespace std;

/*

功能描述：成对出现的数据，利用对组可以返回两个数据

两种创建方式；
    1、pair<type, type> p(value1, value2);
    2、pair<type, type> p = make_pair(value1, value2);

*/

void test01(){
    
    // 第一种方式
    pair<string, int> p("张三", 18);
    cout << "姓名: " << p.first << " 年龄: " << p.second << endl;

    // 第二种方式
    pair<string, int> p2 = make_pair("Jerry" , 20);
    cout << "name: " << p2.first << " age: " << p2.second << endl;
}


int main(){

    test01();

    return 0;
}