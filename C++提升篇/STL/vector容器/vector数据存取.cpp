#include<iostream>
using namespace std;
#include<vector>
/*

函数原型：
    1、at(int idx);  // 返回索引idx所指的数据
    2、operator[];   // 返回索引idx所指的数据
    3、front();      // 返回容器中的第一个元素
    4、back();       // 返回容器中的最后一个元素

*/


void test01(){

    vector<int> v1;

    for (int i=0; i<10; i++){
        v1.push_back(i);
    }

    // 利用[]的方式来访问vector容器中的数据
    for (int i=0; i<v1.size(); i++){
        cout << v1[i] << "  ";
    }
    cout << endl;

    // 利用at()函数来访问vector容器中的数据
    for (int i=0; i<v1.size(); i++){
        if (i <= v1.size()-2 ){
            cout << v1.at(i) << " -> ";
        }
        else{
            cout << v1.at(i);
        }
    }
    cout << endl;

    // 获取容器中的第一个元素
    cout << "容器中的第一个元素: " << v1.front() << endl;
    // 获取容器中的最后一个元素
    cout << "容器中的最后一个元素: " << v1.back() << endl;

}


int main(){

    test01();

    return 0;
}