#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void myPrint(int val){
    cout << val << endl;
};

void test01(){
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // 通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v.begin(); // 起始迭代器，指向容器中的第一个元素
    vector<int>::iterator itEnd = v.end();  // 结束迭代器，指向容器中的最后一个元素的下一位

    // 第一种遍历方式
    cout << "第一种遍历方式: " << endl;
    while (itBegin != itEnd){
        // cout << *itBegin << endl;
        // itBegin++;
        cout << *itBegin++ << endl;  // 上面两步可以合并为一步
    };
    cout << endl;

    // 第二种遍历方式，利用for循环
    cout << "第二种遍历方式: " << endl;
    for (vector<int>::iterator it= v.begin(); it != v.end(); it++){
        cout << *it << endl;
    };
    cout << endl;

    // 第三种遍历方式，利用STL提供的遍历算法
    cout << "第三种遍历方式: " << endl;
    for_each(v.begin(), v.end(), myPrint);
};

int main(){
    test01();

    return 0;
}