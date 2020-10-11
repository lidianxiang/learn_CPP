#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include<algorithm>

/*

功能描述：向容器中填充指定的元素

函数原型：
    fill(iterator_beg, iterator_end, value);

*/

void myPrint(int val){
    cout << val << " ";
}

void test01(){

    vector<int> v;

    v.resize(10);
    cout << "填充前: " << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    fill(v.begin(), v.end(), 100);
    cout << "填充后: " << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;


}


int main(){

    test01();

    return 0;
}