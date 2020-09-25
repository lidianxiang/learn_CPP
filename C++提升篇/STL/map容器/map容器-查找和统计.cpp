#include<iostream>
using namespace std;
#include<map>

/*

函数原型：
    1、find(key);  // 查找key是否存在，若存在，则返回该键的元素的迭代器，若不存在则返回set.end();
    2、count(key);

*/


void test01(){

    map<int, int> mp;
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(3, 30));

    // 查找
    map<int, int>::iterator pos = mp.find(3);

    if (pos != mp.end()){
        cout << "找到了元素: key = " << pos->first << ", value = " << pos->second << endl;
    }
    else{
        cout << "未找到元素" << endl;
    }

    // 统计
    // map不允许插入重复的key元素，count统计而言，结果要么是0，要么是1
    // multimap的count统计可能大于1
    int num = mp.count(3);
    cout << "num = " << num << endl;

}


int main(){

    test01();

    return 0;
}