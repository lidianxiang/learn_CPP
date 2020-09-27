#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*

常用拷贝和替换算法
    1、copy
    2、replace
    3、replace_if
    4、swap

copy算法：容器内指定范围的元素拷贝到另一个容器中

函数原型：
    copy(iterator_beg, iterator_end, iterator dest)

*/

void myPrint(int val){
    cout << val << " ";
}

void test01(){

    vector<int> v1;
    for(int i=0; i<10; i++){
        v1.push_back(i);
    }

    vector<int> v2;
    v2.resize(v1.size());  // 需要提前为v2开辟空间，否则会报错
    copy(v1.begin(), v1.end(), v2.begin());
    for_each(v2.begin(), v2.end(), myPrint);
    cout << endl;

}


int main(){

    test01();

    return 0;
}