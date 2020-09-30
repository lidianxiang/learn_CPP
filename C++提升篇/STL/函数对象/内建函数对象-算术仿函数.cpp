#include<iostream>
using namespace std;
#include<functional>

/*

内建函数：STL内建了一些函数对象，包括算术仿函数、关系仿函数、逻辑仿函数

算术仿函数：实现四则运算，其中negate是一元运算，其他都是二元运算
仿函数原型：
    1、template<class T> T plus<T>       // 加法仿函数
    2、template<class T> T minus<T>      // 减法仿函数
    3、template<class T> T multilies<T>  // 乘法仿函数
    4、template<class T> T divides<T>  // 除法仿函数
    5、template<class T> T modules<T>  // 取模仿函数
    6、template<class T> T negate<T>  // 取反仿函数

*/

// negate 一元仿函数， 取反仿函数
void test01(){

    negate<int> n;
    cout << n(50) << endl;

}

// plus 二元仿函数
void test02(){

    plus<int> p;
    cout << p(1, 2) << endl;
}


int main(){

    test01();
    test02();

    return 0;
}