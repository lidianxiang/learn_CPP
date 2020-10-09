#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>


/*

功能：查找相邻重复的元素

函数原型：
    adjacent_find(iterator_beg, iterator_end);
用以查找相邻重复的元素，返回相邻元素的第一个位置的迭代器

*/


void test01(){

    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());

    if(pos == v.end()){
        cout << "未找到重复相邻的元素" << endl;
    }
    else
    {
        cout << "找到了重复相邻的元素是: " << *pos << endl;
    }
    

}


int main(){

    test01();

    return 0;
}