#include<iostream>
using namespace std;

int main(){

    //如果定义的是浮点型的float类型的话，建议在小数点后面加上字母f，则在运算时少去一步
    // 系统默认会将3.14设置为double类型，如果后面加上f的话，则直接转换为float类型
    float f1 = 3.14f; // 最高6位有效数字
    double f2 = 3.14;
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "float 占用的内存空间为: " << sizeof(float) << endl;  // 4字节
    cout << "double 占用的内存空间为: " << sizeof(double) << endl; // 8字节
    return 0;
}