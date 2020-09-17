// 建立自己的通用的数组类
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray{
public: 
    // 有参构造函数
    MyArray(int capacity){
        // cout << "有参构造函数的调用" << endl;
        this->m_Capacity = capacity;
        this->m_size = 0;
        this->pAddress = new T[this->m_Capacity];
    };

    // 拷贝构造
    MyArray(const MyArray & arr){
        // cout << "拷贝构造函数的调用" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_size = arr.m_size;
        // this->pAddress = arr.pAddress;  // 不能这么做，会导致地址冲突（浅拷贝的问题）

        // 深拷贝
        this->pAddress = new T[arr.m_size];

        // 将arr中的数据都拷贝过来
        for (int i=0; i < this->m_size; i++){
            this->pAddress[i] = arr.pAddress[i];
        };
    };

    // operator=防止浅拷贝的问题
    MyArray& operator=(const MyArray& arr){
        // cout << "operator=的调用" << endl;
        // 先判断堆区中是否有数据，如果有则需要将其清空
        if (this->pAddress != NULL){
            delete[] this->pAddress;
            this->m_size = 0;
            this->m_Capacity = 0;
        };

        // 深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_size = arr.m_size;
        this->pAddress = new T[arr.m_Capacity];

        for (int i=0; i < this->m_size; i++){
            this->pAddress[i] = arr.pAddress[i];
        };
        return *this;

    };

    // 尾插法
    void Push_Back(const T & val){
        // 判断容量是否已经满了
        if (this->m_Capacity == this->m_size){
            return;
        };
        this->pAddress[m_size] = val;  // 在数组的末尾插入数据
        this->m_size++;  // 更新数组大小
    };

    // 尾删法
    void Pop_Back(){
        // 让用户访问不到最后一个元素，即为尾删，逻辑上的删除
        if (this->m_size == 0){
            return;
        };
        this->m_size--;
    };

    // 通过下标方式访问数组中的元素，如果需要将其作为左值，则需要返回其的引用形式
    T& operator[](int index){
        return this->pAddress[index];
    };

    // 返回数组的容量
    int getCapacity(){
        return this->m_Capacity;
    }
    // 返回数组的大小
    int getSize(){
        return this->m_size;
    };

    // 析构函数
    ~MyArray(){
        if (this->pAddress != NULL){
            // cout << "析构函数的调用" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
        };
    };

private:
    T * pAddress; // 指针指向堆区开辟的真是数组
    int m_Capacity; // 数组容量
    int m_size;  // 数组的大小
};