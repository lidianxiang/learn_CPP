#include<iostream>
using namespace std;

// new的基本语法
int * func(){
    // new返回的是该数据类型的指针
    int * p = new int(10);
    return p;
}

void test01(){
    int * p1 = func();
    cout << *p1 << endl;
    // 堆区的数据由程序员管理开辟和释放，使用关键字delete
    delete p1;
    // cout << *p1 << endl;
}

void test02(){
    // new出来一个数组
    int * arr = new int[10];
    // 赋值
    for (int i=0; i<10; i++){
        arr[i] = i + 100;
    }
    // 打印
    for (int i=0; i<10; i++){
        cout << arr[i] << endl;
    }
    //释放数组空间
    delete[] arr;
}


int main(){
    // test01();
    test02();
    return 0;
}