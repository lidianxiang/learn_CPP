#include<iostream>
using namespace std;
#include<vector>

/*

功能：vector数据结构和数组非常相似，也称为单端数组

vector与普通数组的区别在于：
    数组是静态空间，而vector可以动态扩展，动态扩展并不是在原空间之后续接新的空间，而是找更大的内存空间，
然后将原数据拷贝到新空间，释放掉原空间。

函数原型：
    1、vector<T> v;  //采用模版实现类实现，默认构造函数
    2、vector(v.begin(), v.end());   // 将v[begin(), end())区间中的元素拷贝给本身
    3、vector(n, elem);   // 构造函数将n个elem拷贝给本身
    4、vector(const vector &vec);  // 拷贝构造函数

*/

void printVector(vector<int> &v){
    for(vector<int>::iterator it=v.begin(); it != v.end(); it ++){
        cout << *it << " ";
    };
    cout << endl;
};

void test01(){
    // 默认构造，无参构造
    vector<int> v1;

    for(int i=0; i<10; i++){
        v1.push_back(i);
    };
    printVector(v1);

    // 通过区间的形式
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    // n个elem方式构造
    vector<int> v3(10, 100);
    printVector(v3);

    // 拷贝构造的形式
    vector<int> v4(v3);
    printVector(v4);

};


int main(){

    test01();
    return 0;
}