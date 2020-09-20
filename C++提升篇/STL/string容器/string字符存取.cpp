#include<iostream>
using namespace std;
#include<string>

void test01(){

    string str1 = "hello";
    // 通过[]来访问单个字符
    for (int i=0; i< str1.size(); i++){
        cout << str1[i] << "  ";
    }
    cout << endl;
    // 通过string的at()函数来访问单个字符
    for (int i=0; i<str1.size(); i++){
        cout << str1.at(i) << " ";
    }
    cout << endl;

    // 修改单个字符
    str1[0] = 'x';
    cout << "str1 = " << str1 << endl;

    str1.at(1) = 'x';
    cout << "str1 = " << str1 << endl;
};

int main(){

    test01();

    return 0;
}