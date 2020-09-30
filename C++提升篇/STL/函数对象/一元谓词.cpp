#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*

谓词：
    1、返回bool类型的仿函数称为谓词
    2、如果operator()接受一个参数，那么叫做一元谓词
    3、如果operator()接受两个参数，那么叫做二元谓词

*/

class GreaterFive{
public:
    bool operator()(int val){
        return val > 5;
    }
};

void test01(){
    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }

    // 查找容器中，有没有大于5的数字
    // GreaterFive()是匿名函数对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end()){
        cout << "未找到" << endl;
    }
    else{
        cout << "找到了大于5的数字: " << *it << endl;
    }

}

int main(){

    test01();

    return 0;
}