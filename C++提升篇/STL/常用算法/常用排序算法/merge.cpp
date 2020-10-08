#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*

功能描述：两个容器元素合并，并存储到另一个容器中

函数原型：
    merge(iterator_beg1, iterator_end1, iterator_beg2, iterator_end2, iterator_dest)

注意：两个容器必须是有序的

*/

class MyPrint{
public:
    void operator()(int val){
        cout << val << " ";
    }
};


void test01(){

    vector<int> v1;
    vector<int> v2;

    for(int i=0; i<10; i++){
        v1.push_back(i);
        v2.push_back(i+2);
    }

    // 目标容器
    vector<int> vTarget;
    vTarget.resize(v1.size() * 2);  // 需要提前设置容器的容量大小

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), vTarget.end(), MyPrint());
    cout << endl;
}


int main(){

    test01();

    return 0;
}