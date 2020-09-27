#include<iostream>
using namespace std;
#include<set>

/*

函数原型：
    1、find(key);  // 查找key是否存在，若存在，返回该键的元素的迭代器，若不存在，返回set.end();
    2、count(key);  // 统计key的元素的个数

*/

void findElem(set<int> &s, int key){
    set<int>::iterator pos = s.find(key);
    if (pos != s.end())
    {
        cout << "找到了元素: " << *pos << endl;
    }
    else
    {
        cout << "未找到查找的元素" << endl;
    }
}


void test01(){

    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    // set<int>::iterator pos = s1.find(30);
    findElem(s1, 30);
    findElem(s1, 50);
    // if (pos != s1.end()){
    //     cout << "找到了元素: " << *pos << endl;
    // }
    // else
    // {
    //     cout << "未找到查找的元素" << endl;
    // }
    
}


int main(){

    test01();

    return 0;
}
