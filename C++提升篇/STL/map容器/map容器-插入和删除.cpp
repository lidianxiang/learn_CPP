#include<iostream>
using namespace std;
#include<map>

/*

函数原型：
    1、insert(elem);
    2、clear();
    3、erase(pos);
    4、erase(beg, end);
    5、erase(key);

*/

void printMap(map<int, int> &mp){
    for(map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
        cout << "key = " << it->first << ", value = " << it->second << endl;
    }
    cout << endl;
}

void test01(){

    map<int, int> mp;

    // 第一种插入方式
    mp.insert(pair<int, int>(1, 10));

    // 第二种插入方式
    mp.insert(make_pair(2, 20));

    // 第三种插入方式
    mp.insert(map<int, int>::value_type(3, 30));

    // 第四种插入方式
    mp[4]= 40;  // 不建议使用这种方式来插入数据，因为如果key值不存在，系统会默认输出0

    printMap(mp);

    // 删除
    mp.erase(mp.begin());
    printMap(mp);

    mp.erase(4);
    printMap(mp);

    mp.erase(mp.begin(), mp.end());
    printMap(mp);
}


int main(){

    test01();

    return 0;
}