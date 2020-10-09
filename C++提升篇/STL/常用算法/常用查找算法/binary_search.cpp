#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>


/*

函数原型：
    bool binary_search(iterator_beg, iterator_end, value);
查找指定的元素，查到则返回true，否则返回false, ⚠️注意：在无序序列中不可以使用的

*/

void test01(){

    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }

    bool res = binary_search(v.begin(), v.end(), 7);
    if (res){
        cout << "找到了" << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}


int main(){

    test01();

    return 0;
}