#include<iostream>
using namespace std;
#include<vector>
#include<numeric>


/*

算术生成算法属于小型算法，使用时包含的头文件为  #include<numeric>

算法简介:
    1、accumulate   // 计算容器元素的累加和
    2、fill    // 向容器中添加元素

函数原型：
    accumulate(iterator_beg, iterator_end, value)  // value为起始值

*/

void test01(){

    vector<int> v;
    for(int i=1; i<=100; i++){
        v.push_back(i);
    }

    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "sum = " << sum << endl;

}


int main(){

    test01();

    return 0;
}