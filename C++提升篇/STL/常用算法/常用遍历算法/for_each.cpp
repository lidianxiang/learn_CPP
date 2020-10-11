#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*

常用算法
    1、算法主要是由头文件<algorithm> <functional> <numeric>组成
    2、<algorithm>是所有STL头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、赋值、修改等
    3、<numeric>体积很小，只包括几个在序列上面进行简单数学运算的模版函数
    4、<functional>定义了一些模版类，用以声明函数对象


常用的遍历算法：
    1、for_each()   // 遍历容器
    2、transform()   // 搬运容器到另一个容器中

for_each函数原型
    for_each(iterator_beg, iterator_and, _func)

*/

// 普通函数
void myPrint(int val){
    cout << val << " ";
}

// 仿函数
class myPrint2{
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

    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
    for_each(v.begin(), v.end(), myPrint2());

}


int main(){

    test01();

    return 0;
}