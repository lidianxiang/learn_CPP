#include<iostream>
using namespace std;
#include<map>
/*

函数原型：
    1、size();
    2、empty();
    3、swap(st);

*/

void printMap(map<int, int> &mp){
    for(map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
        cout << "key = " << it->first << ", second = " << it->second << endl;
    }
    cout << endl;
}

void test01(){

    map<int, int> mp;
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(3, 30));

    if (mp.empty()){
        cout << "容器为空" << endl;
    }
    else{
        cout << "容器不为空" << endl;
        cout << "容器大小为: " << mp.size() << endl;
    }

    // 交换
    map<int, int> mp2;
    mp2.insert(pair<int, int>(30, 3));
    mp2.insert(pair<int, int>(20, 2));
    mp2.insert(pair<int, int>(1, 10));

    cout << "交换前: " << endl;
    printMap(mp);
    printMap(mp2);

    mp.swap(mp2);

    cout << "交换后: " << endl;
    printMap(mp);
    printMap(mp2);

}

int main(){

    test01();

    return 0;
}