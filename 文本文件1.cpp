#include<iostream>
using namespace std;
#include<fstream>

// 文件文件写文件
void test01(){
    // 创建流对象
    ofstream ofs;
    // 指定打开方式
    ofs.open("文本文件.txt", ios::out);
    // 开始写文件
    ofs << "姓名: 张三" << endl;
    ofs << "性别: 男" << endl;
    ofs << "年龄: 18" << endl;
    // 关闭文件
    ofs.close();
};

int main(){

    test01();

    return 0;
}