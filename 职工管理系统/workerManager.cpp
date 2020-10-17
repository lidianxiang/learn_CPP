#include "workerManager.h"
#include <cstdlib>
#include <cstdlib>

WorkerManager::WorkerManager(){

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    // 1、文件不存在的情况
    if (!ifs.is_open()){
        // cout << "文件不存在" << endl;
        this->m_EmpNum = 0; // 初始化记录人数
        this->m_FileEmpty = true;  // 初始化文件是否为空
        this->m_EmpArray = NULL;  // 初始化数组指针
        ifs.close();
        return;
    }

    // 2、文件存在，并且没有记录
    char ch;
    ifs >> ch;  // 用ifs去向右移动一个字符来判断是否读到了eof，读到了eof则表示文件为空
    if(ifs.eof()){
        // cout << "文件为空!" << endl;
        this->m_EmpNum = 0;
        this->m_FileEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return ;
    }
    // 3、当文件存在，且记录有数据的情况
    int num = this->get_EmpNum();
    // cout << "职工人数为: " << num << endl; 
    this->m_EmpNum = num;

    // 根据职工数创建数组
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    // 初始化职工
    this->init_Emp();

    // // 测试代码
    // for(int i=0; i<m_EmpNum; i++){
    //     cout << "职工号: " << this->m_EmpArray[i]->m_Id 
    //          << "\t职工姓名: " << this->m_EmpArray[i]->m_Name
    //          << "\t部门编号: " << this->m_EmpArray[i]->m_DeptId << endl;
    // }

}

void WorkerManager::Show_Menu(){
    cout << "**************************************" << endl;
    cout << "*******  欢迎使用职工管理系统  *******" << endl;
    cout << "**********  0.退出管理系统  **********" << endl;
    cout << "**********  1.增加职工信息  **********" << endl;
    cout << "**********  2.显示职工信息  **********" << endl;
    cout << "**********  3.删除职工信息  **********" << endl;
    cout << "**********  4.修改职工信息  **********" << endl;
    cout << "**********  5.查找职工信息  **********" << endl;
    cout << "**********  6.按照编号排序  **********" << endl;
    cout << "**********  7.清空所有文档  **********" << endl;
    cout << "**************************************" << endl;
    cout << endl;
}

void WorkerManager::ExitSystem(){
    cout << "欢迎下次使用" << endl;
    exit(0);
}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);  // 写文件

    // 将每个人的数据写入至文件中
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
}

int WorkerManager::get_EmpNum(){

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId){
        // 记录人数
        num++;
    }
    return num;

}

void WorkerManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while(ifs >> id && ifs >> name && ifs >> dId){
        Worker * worker = NULL;

        // 根据不同的部门id创建不同对象
        if (dId == 1){
            worker = new Employee(id, name, dId);
        }
        else if(dId == 2){
            worker = new Manager(id, name, dId);
        }
        else
        {
            worker = new Boss(id, name, dId);
        }

        // 存放到数组中
        this->m_EmpArray[index] = worker;
        index++;    
    }

    // 关闭文件
    ifs.close();
}

// 显示职工
void WorkerManager::Show_Emp(){
    if (this->m_FileEmpty){
        cout << "文件不存在或记录为空!" << endl;
    }

    else{
        for(int i=0; i<m_EmpNum; i++){
            // 利用多态调用接口
            this->m_EmpArray[i]->showInfo();
        }
    }

    // system("clear");
}

void WorkerManager::Add_Emp(){
    cout << "请输入增加职工的数量: " << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0){

        // 计算新空间的大小
        int newSize = this->m_EmpNum + addNum;

        // 开辟新空间
        Worker ** newSpace = new Worker*[newSize];

        // 将原空间下内容存放到新空间下
        if (this->m_EmpArray != NULL){
            for(int i=0; i< this->m_EmpNum; i++){
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        // 输入新数据
        for(int i=0; i<addNum; i++){
            int id;  // 职工编号
            string name;  // 职工姓名
            int dSelect;   // 部门选择

            cout << "请输入第" << i + 1 << " 个新职工编号: " << endl;
            cin >> id;

            cout << "请输入第" << i + 1 << " 个新职工姓名: " << endl;
            cin >> name;

            cout << "请选择该职工的岗位: " << endl;
            cout << "1、普通员工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker * worker = NULL;
            switch(dSelect){
            case 1:  // 普通员工
                worker = new Employee(id, name, 1);
                break;

            case 2:   // 经理
                worker = new Manager(id, name, 2);
                break;
            case 3:   // 老板
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            } 
            newSpace[this->m_EmpNum + i] = worker;
        }

        // 释放原有空间
        delete[] this->m_EmpArray;

        // 更改新空间的指向
        this->m_EmpArray = newSpace;

        // 更新新的个数
        this->m_EmpNum = newSize;

        // 将文件标志至false
        this->m_FileEmpty = false;

        // 提示信息
        cout << "成功添加" << addNum << "名新职工！" << endl;

        // 保存到文件中
        this->save();
    }
    else{
        cout << "输入有误" << endl;
    }

    system("clear");
}

// 删除员工
void WorkerManager::Del_Emp(){
    if(this->m_FileEmpty){
        cout << "文件不存在或记录为空!" << endl;
    }
    else
    {
        // 按照职工编号删除
        cout << "请输入想要删除的员工编号: " << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);
        if (index != -1){ // 说明职工存在，并且要删除掉index位置上的员工

            // 将数据前移，以达到删除的目的
            for( int i=index; i<this->m_EmpNum - 1; i++){
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }

            // 更新数组中记录人员的个数
            this->m_EmpNum--;
            // 数据要同步到文件中
            this->save();
            cout << "删除成功!" << endl;
        }
        else{
            cout << "删除失败，未找到该职工" << endl;
        }

    }
}

// 判断职工是否存在
int WorkerManager::IsExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_Id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

// 修改职工
void WorkerManager::Mod_Emp(){
    if(this->m_FileEmpty){
        cout << "文件不存在或记录为空!" << endl;
    }
    else
    {
        cout << "请输入修改职工的编号" << endl;
        int id;
        cin >> id;
        // 查找该员工
        int ret = this->IsExist(id);
        if(ret != -1)
        { // 查到了编号的员工

            // 删除这个职工的信息
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "查到: " << id << "号职工, 请输入新职工号:  " << endl;
            cin >> newId;

            cout << "请输入新姓名: " << endl;
            cin >> newName;

            cout << "请输入岗位: " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker * worker = NULL;
            switch (dSelect)
            {
            case 1:  // 普通职工
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:  // 经理
                worker = new Manager(newId, newName, dSelect);
                break;       
            case 3:   // 老板
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
            }

            // 更新数据至数组中
            this->m_EmpArray[ret] = worker;

            // cout << "修改成功!" << this->m_EmpArray[ret]->m_DeptId << endl;
            cout << "修改成功!" << endl;

            // 保存到文件中
            this->save();
        }
        else
        {
            cout << "修改失败，查无此人" << endl;
        }
        
    }
    
}

void WorkerManager::Find_Emp(){
    if(this->m_FileEmpty){
        cout << "文件不存在或记录为空" << endl;
    }
    else{
        cout << "请输入查找的方式" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;

        int select = 0;
        cin >> select;

        if (select == 1){  // 按职工编号查找
            int id;
            cout << "请输入查找的职工编号: " << endl;
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1){
                cout << "查找成功！该职工信息如下: " << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        else if(select == 2){   // 按照姓名来查找

            string name;
            cout << "请输入查找的姓名: " << endl;
            cin >> name;

            bool flag = false;  // 查找的标志位
            for(int i=0; i<m_EmpNum; i++){
                if(m_EmpArray[i]->m_Name == name){
                    cout << "查找成功, 职工编号为: "
                         << m_EmpArray[i]->m_Id
                         << " 号的信息如下: " << endl;
                    flag = true;
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if(flag == false){
                cout << "查找失败, 查无此人" << endl;
            }

        }
        else{
            cout << "输入选项有误！" << endl;
        }
    }
}

void WorkerManager::Sort_Emp(){
    if(this->m_FileEmpty){
        cout << "文件不存在或记录为空" << endl;
    }
    else{
        cout << "请选择排序的方式: " << endl;
        cout << "1、按职工工号进行升序" << endl;
        cout << "2、按职工工号进行降序" << endl;

        int select = 0;
        cin >> select;
        // 选择排序
        for (int i=0; i<m_EmpNum; i++){
            int minOrMax = i;
            for(int j=i+1; j<m_EmpNum; j++){
                if (select == 1){  // 升序
                    if(m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id){
                        minOrMax = j;
                    }
                }
                else{  // 降序
                    if(m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id){
                        minOrMax = j;
                    }
                }
            }

            if(i != minOrMax){
                Worker * temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = temp;
            }
        }

        cout << "排序成功，排序后的结果为: " << endl;
        this->Show_Emp();
        this->save();
    }
}

void WorkerManager::Clean_File(){

    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1){
        // 打开模式 ios::trunc 如果存在，删除文件并重新创建
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if(this->m_EmpArray != NULL){
            // 删除堆区的每一个元素
            for(int i=0; i < this->m_EmpNum; i++){
                if(this->m_EmpArray[i] != NULL){
                    delete this->m_EmpArray[i];
                    this->m_EmpArray[i] = NULL;
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileEmpty = true;
        }
        cout << "清空成功！" << endl;
    } 

}

// 析构函数
WorkerManager::~WorkerManager(){
    if(this->m_EmpArray != NULL){
        for(int i=0; i<this->m_EmpNum; i++){
            if (this->m_EmpArray[i] != NULL){
                delete this->m_EmpArray[i];
            }
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }

}