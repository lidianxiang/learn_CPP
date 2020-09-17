#include<iostream>
using namespace std;
#include<string>

/*

功能描述： 
    1、查找：查找指定字符串是否存在
    2、替换：在指定的位置替换字符串

函数原型：
    1、int find(const string& str, int pos=0) const;  // 查找str第一次出现的位置，从pos开始查找
    2、int find(const char* s, int pos=0) const;   // 查找s第一次出现的位置，从pos开始查找
    3、inf find(const char* s, int pos, int n) const;  // 从pos位置查找s的前n个字符第一次位置
    4、int find(const char c, int pos=0) const;  // 查找字符c第一次出现的位置
    5、int rfind(const string& str, int pos=npos) const;   // 查找str最后一次的位置，从pos开始查找
    6、int rfind(const char* s, int pos=npos) const;  // 查找s最后一次出现的位置，从pos开始查找
    7、int rfind(const char* s, int pos, int n) const;  // 从pos查找查找的前n个字符最后一次位置
    8、int rfind(const char c, int pos=0) const;  // 查找字符c最后一次出现的位置
    9、string& replace(int pos, int n, const string& str); // 替换从pos开始n个字符为字符串str
    10、string& replace(int pos, int n, const char* s);  // 替换从pos开始的n个字符为字符串s

*/

void test01(){

    string str1 = "abcdefde";
    int pos = str1.find("de");
    int pos2 = str1.find("ed");
    cout << "pos = " << pos << endl;  // 找到了，返回第一次出现的索引值
    cout << "pos2 = " << pos2 << endl;  // 没有找到，返回-1

    if (pos == -1){
        cout << "未找到字符串" << endl;
    }
    else{
        cout << "pos = " << pos << endl;
    }

    // rfind从从右往左查询的，而find是从左往右查询的
    int pos3 = str1.rfind("de");
    cout << "pos3 = " << pos3 << endl;

};

// 替换
void test02(){
    string str1 = "abcdefg";
    str1.replace(1,3, "1111");
    cout << "str1 = " << str1 << endl;
};


int main(){

    test01();

    test02();

    return 0;
}