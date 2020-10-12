#include<iostream>
using namespace std;
#include<cstdlib>
#include "globalFile.h"
#include "Identity.h"
#include<fstream>
#include "student.h"
#include "teacher.h"
#include "manager.h"


/*

机房预约系统
1.1 系统简介
    学校有几个规格不同的机房，由于使用时经常出现“撞车”现象，现开发一套机房预约的系统，解决这个问题。

1.2 身份简介
    分别有三种身份来使用这个程序
        学生代表：申请使用机房
        教师：审核学生的预约申请
        管理：给学生、教师创建账号

1.3 机房简介
    机房总共有3间
        1号机房 -- 最大容量为20人
        2号机房 -- 最大容量为50人
        3号机房 -- 最大容量为100人
1.4 申请简介
    申请的订单每周由管理员负责清空
    学生可以预约未来一周内的机房使用，预约的日期为周一和周五，预约时需要选择预约的时段（上午或下午）
    教师来审核预约，依据实际情况审核预约通过或者不通过

1.5 系统具体需求
    a. 首先进入登陆界面，可选登陆身份有：
        学生代表、老师、管理员、退出
    b. 每个身份都需要进行验证后，进入子菜单
        学生需要输入：学号、姓名、登陆密码
        老师需要输入：职工号、姓名、登陆密码
        管理员需要输入：管理员姓名、登陆密码
    c. 学生具体功能
        申请预约 -- 预约机房
        查看自身的预约 -- 查看自己的预约状态
        查看所有的预约 -- 查看全部预约信息以及预约状态
        取消预约 -- 取消自身的预约，预约成功后审核中的预约均可以取消
    d. 教师具体功能
        查看所有的预约 -- 查看全部预约信息以及预约状态
        审核预约 -- 对学生的预约进行审核
        注销登陆 -- 退出登陆
    e. 管理员具体功能
        添加账号 -- 添加学生或教师的账号，需要检测学生编号或教师职工号是否需要
        查看账号 -- 可以选择查看学生或教师的全部信息
        查看机房 -- 查看所有机房的信息    
        清空预约 -- 清空所有预约记录
        注销登陆 -- 退出登录

*/

// 管理员菜单
void managerMenu(Identity * & manager)
{
    while (true)
    {
        // 管理员菜单
        manager->operMenu();
        // 指针进行强制转换,将父类指针转换为子类指针，调用子类里的其他接口
        Manager * man = (Manager*)manager;
        int select = 0;
        cin >> select;

        if (select == 1)   // 添加账号
        {
            // cout << "添加账号" << endl;
            man->addPerson();
        }
        else if(select == 2)
        {
            // cout << "查看账号" << endl;
            man->showPerson();
        }
        else if(select == 3)
        {
            // cout << "查看机房" << endl;
            man->showComputer();
        }
        else if(select == 4)
        {
            // cout << "清空预约" << endl;
            man->cleanFile();
        }
        else
        {
            delete manager;  // 销毁掉堆区的对象
            cout << "注销成功" << endl;
            return ;
        }
        
    }
}

// 学生菜单
void studentMenu(Identity *&student)
{
    while (true)
    {
        // 学生菜单
        student->operMenu();

        Student *stu = (Student *)student;
        int select = 0;
        cin >> select;

        if (select == 1) // 申请预约
        {
            stu->applyOrder();
        }
        else if (select == 2) // 查看自身预约
        {
            stu->showMyOrder();
        }
        else if (select == 3) // 查看所有预约
        {
            stu->showAllOrder();
        }
        else if (select == 4) // 取消预约
        {
            stu->cancelOrder();
        }
        else
        {
            delete student;
            cout << "注销成功 " << endl;
            return;
        }
    }
}

// 教师菜单
void TeacherMenu(Identity * &teacher)
{
    while(true)
    {
        // 教师菜单
        teacher->operMenu();

        Teacher* tea = (Teacher*)teacher;
        int select = 0;
        cin >> select;

        if (select == 1)
        {
            // 查看所有的预约
            tea->showAllOrder();
        }
        else if (select == 2)
        {
            // 审核预约
            tea->validOrder();
        }
        else 
        {
            delete teacher;
            cout << "注销成功" << endl;
            return;
        }
    }
}

// 登录功能
void LoginIn(string fileName, int type)
{
    Identity * person = NULL;

    ifstream ifs;
    ifs.open(fileName.c_str(), ios::in);

    // 文件不存在的情况
    if(!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    int id = 0;  // 接受用户的学号或职工号
    string name;
    string pwd;

    if (type == 1)  // 学生登录
    {
        cout << "请输入你的学号" << endl;
        cin >> id;
    }
    else if (type == 2)
    {
        cout << "请输入你的职工号" << endl;
        cin >> id;
    }

    cout << "请输入用户名: " << endl;
    cin >> name;

    cout << "请输入密码: " << endl;
    cin >> pwd;

    if (type == 1)
    {
        // 学生登录验证
        int fId;
        string fName;
        string fPwd;

        while(ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if(id == fId && name == fName && pwd == fPwd)
            {
                cout << "学生验证登录成功!" << endl;
                person = new Student(id ,name, pwd);
                // 进入到学生身份的子菜单
                studentMenu(person);
                return ;
            }
        }
    }
    else if (type == 2)
    {
        // 教师登录验证
        int fId;
        string fName;
        string fPwd;
        while(ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (id == fId && name == fName && pwd == fPwd)
            {
                cout << "教师验证登录成功！" << endl;
                person = new Teacher(id, name, pwd);
                // 进入到教师的子菜单界面
                TeacherMenu(person);
                return;
            }
        }
    }
    else if (type == 3)
    {
        // 管理员登录验证
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd)
        {
            if(name == fName && pwd == fPwd)
            {
                cout << "验证登录成功！" << endl;
                // 创建管理员对象
                person = new Manager(name, pwd);
                // 进入管理员子菜单
                managerMenu(person);
                return ;
            }
        }
    }

    cout << "验证登录失败！" << endl;

    return;

}


int main(){

    int select = 0;
    while (true)
    {

        cout << "===================== 欢迎进入机房预约系统 =====================" << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t ---------------------------------------------\n";
        cout << "\t\t|                                             |\n";
        cout << "\t\t|                  1. 学生代表                |\n";
        cout << "\t\t|                                             |\n";
        cout << "\t\t|                  2. 老    师                |\n";
        cout << "\t\t|                                             |\n";
        cout << "\t\t|                  3. 管 理 员                |\n";
        cout << "\t\t|                                             |\n";
        cout << "\t\t|                  0. 退    出                |\n";
        cout << "\t\t|                                             |\n";
        cout << "\t\t ---------------------------------------------\n";
        cout << "请输入您的选择: ";

        cin >> select;  // 接受用户的输入

        switch (select)
        {
        case 1:    // 学生身份
            LoginIn(STUDENT_FILE, 1);
            break;

        case 2:    // 老师身份
            LoginIn(TEACHER_FILE, 2);
            break;

        case 3:    // 管理员身份
            LoginIn(ADMIN_FILE, 3);
            break;
            
        case 0:    // 退出
            cout << "欢迎下次使用" << endl;
            return 0;
            break;
        default:
            cout << "输入有误，请重新输入" << endl;
            // do
            // {
            //     cout << "Press the Enter key to continue.";
            // } while (cin.get() != '\n');
            // system("clear");
            break;
        }

    }

    return 0;
}