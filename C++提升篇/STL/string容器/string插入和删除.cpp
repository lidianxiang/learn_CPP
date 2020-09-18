#include<iostream>
using namespace std;
#include<string>

void test01(){

    string str1 = "hello";
    cout << "str1 = " << str1 << endl;
    // 插入
    str1.insert(1, "111");
    cout << "str = " << str1 << endl;

    // 删除
    str1.erase(1, 3);
    cout << "str1 = " << str1 << endl;

};

int main(){

    test01();

    return 0;
}