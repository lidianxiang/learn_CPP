#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*

功能描述：将区间内满足条件的元素，替换成指定的元素

函数原型：
    replace_if(iterator_beg, iterator_end, _Pred, newValue)

*/

class MyPrint{
public:
    void operator()(int val){
        cout << val << " ";
    }
};

class Greater5{
public:
    bool operator()(int val){
        return val >= 5;
    }

};


void test01(){

    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }

    cout << "替换前: " << endl;
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

    // 将大于等于5的数替换成5000
    replace_if(v.begin(), v.end(), Greater5(), 5000);
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}


int main(){

    test01();

    return 0;
}