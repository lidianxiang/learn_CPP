#include<iostream>
using namespace std;

int main(){
    /*
    1、创建字符型变量要用单引号
    2、创建字符型变量，单引号内只能有一个字符
    */
    char ch = 'a';
    cout << "ch =  " << ch << endl;
    cout << "字符型变量所占的空间: " << sizeof(ch) << "字节"<< endl;
    // 字符串转ASCII
    cout << "ch对应的ASCII是: " << (int)ch << endl;

    return 0;
}