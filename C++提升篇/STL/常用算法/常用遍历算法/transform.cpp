#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*

函数原型：
    transform(iterator_beg1, iterator_end1, iterator_beg2, _func)
其中，iterator_beg1,iterator_end1表示源容器开始和结束迭代器的位置
     iterator_beg2表示目标容器开始迭代器
     _func表示函数或函数对象

*/

// 仿函数
class Transform{
public:
    int operator()(int val){
        return val + 1000;
    }
};

// 仿函数
class MyPrint{
public:
    void operator()(int val){
        cout << val << " ";
    }
};

void test01(){

    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }

    vector<int> vTarget;   // 目标容器
    vTarget.resize(v.size());  // 目标容器需要提前开辟空间

    // 容器转移
    transform(v.begin(), v.end(), vTarget.begin(), Transform());
    // 打印目标容器
    for_each(vTarget.begin(), vTarget.end(), MyPrint());

}


int main(){

    test01();

    return 0;
}
