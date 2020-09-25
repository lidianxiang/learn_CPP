#include<iostream>
using namespace  std;
#include<map>

/*

map基本概念：
    1、map中所有元素都是pair
    2、pair中的第一个元素为key，起到索引的作用，第二个元素是value
    3、所有元素都会根据元素的键值自动排序

本质：
    map/multimap属于关联式容器，底层结果是用二叉树实现的

优点：
    可以根据key值快速找到value值
map/multimap区别：
    1、map不允许容器中有重复的key值元素
    2、multimap允许容器中有重复的key值元素

函数原型：
构造：
    1、map<T1, T2> mp; // map默认构造函数 
    2、map(const map &mp);  // 拷贝构造函数

赋值：
    map& operator=(const map &mp); // 重载等号操作符

*/

void printMap(map<int, int> &mp){
    for(map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
        cout << "key = " << it->first << ", value = " << it->second << endl;
    }
    cout << endl;
}

void test01(){

    // 默认构造
    map<int, int> mp;

    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(3, 30));
    mp.insert(pair<int, int>(4, 40));
    printMap(mp);

    // 拷贝构造
    map<int, int> mp2(mp);
    printMap(mp2);

    // 赋值
    map<int, int> mp3;
    mp3 = mp;
    printMap(mp3);
}

int main(){

    test01();

    return 0;
}