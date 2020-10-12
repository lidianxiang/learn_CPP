#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*
函数原型：
    set_union(iterator_beg1, iterator_end1, iterator_beg2, iterator_end2, iterator_dest)

注意：两个集合必须是有序序列

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
        v2.push_back(i+5);
    }

    // 目标容器
    vector<int> vTarget;
    vTarget.resize(v1.size() + v2.size());

    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, MyPrint());
    cout << endl;

}


int main(){

    test01();

    return 0;
}