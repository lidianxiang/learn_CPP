#pragma once 
#include<iostream>
using namespace std;
#include "Identity.h"
#include<vector>
#include<fstream>
#include "globalFile.h"
#include "computerRoom.h"
#include "orderFile.h"
#include "stdlib.h"

// 学生类
class Student: public Identity
{
public:
    // 默认构造
    Student();

    // 有参构造
    Student(int id, string name, string pwd);

    // 菜单界面
    virtual void operMenu();

    // 申请预约
    void applyOrder();

    // 查看我的预约
    void showMyOrder();

    // 查看所有预约
    void showAllOrder();

    // 取消预约
    void cancelOrder();

    // 学生学号
    int m_Id;

    // 机房容量
    vector<ComputerRoom> vCom;

};