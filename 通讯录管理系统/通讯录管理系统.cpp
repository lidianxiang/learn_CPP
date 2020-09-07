#include<iostream>
using namespace std;
#include<cstdlib>

#define MAX 1000 // 最大人数

// 联系人的结构体
struct Person{
    string m_Name;  // 姓名
    int m_Sex;  // 性别
    int m_Age;  // 年龄
    string m_Phone;  // 电话号码
    string m_Addr;  // 家庭住址
};

// 通讯录的结构体
struct Addressbooks{
    struct Person personArray[MAX];  // 通讯录中保存的联系人数组
     int m_Size; // 通讯录中当前人员的个数
};

// 添加联系人
void addPerson(Addressbooks * abs){
    if (abs->m_Size == 1000){
        cout << "通讯录已满，无法添加" << endl;
        return ;
    }
    else{
        // 姓名
        string name;
        cout << "请输入姓名: " << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        // 性别
        cout << "请输入性别: " << endl;
        cout << "1 --- 男 " << endl;
        cout << "2 --- 女 " << endl;
        int sex = 0;  // 初始化一个sex变量用于保存用户输入的数字

        while(true){
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误， 请重新输入！" << endl;
        }

        // 年龄
        cout << "请输入年龄: " << endl;
        int age = 0;
        cin >> age;
        while (true)
        {
            if (age <= 0 || age > 100){
                cout << "年龄输入有误， 请重新输入！" << endl;
                break;
             }
             abs->personArray[abs->m_Size].m_Age = age;
             break;
        }
        // 电话
        cout << "请输入联系电话: " << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        // 地址
        cout << "请输入家庭住址: " << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        // 更新通讯录人数
        abs->m_Size++;
        cout << "添加成功！" << endl;
        // system("clear");
        
    }
};

//显示所有的联系人信息
void showPerson(Addressbooks * abs){
    if (abs->m_Size == 0){
        cout << "当前的记录为空" << endl;
    }
    else{
        for (int i=0; i < abs->m_Size; i++){
            cout << "姓名: " << abs->personArray[i].m_Name << "\t";
            // 利用三目运算符将数字转化为字符串
            cout << "性别: " << (abs->personArray[i].m_Sex == 1? "男": "女") << "\t";
            cout << "年龄: " << abs->personArray[i].m_Age << "\t";
            cout << "电话: " << abs->personArray[i].m_Phone << "\t";
            cout << "住址: " << abs->personArray[i].m_Addr << endl;
        } 
    }
};

/*
检测联系人是否存在，如果存在，返回联系人所在数组中的位置，否则返回-1
*/
int isExist(Addressbooks *abs, string name){
    // 遍历数组来查找是否存在这个要查找的姓名
    for (int i=0; i < abs->m_Size; i++){
        if (abs->personArray[i].m_Name == name){
            return i;
        }       
    }
    return -1;
};

void deletePerson(Addressbooks * abs){
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1){
        for (int i=ret; i < abs->m_Size; i++){
            // 数据前移
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--; // 更新通讯录的人员数
        cout << "删除成功！"<<endl;
    }
    else {
        cout << "查无此人" << endl;
    }
};

void findPerson(Addressbooks * abs){
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1){
        cout << "姓名: " << abs->personArray[ret].m_Name << "\t";
        cout << "性别: " << (abs->personArray[ret].m_Sex == 1? "男": "女") << "\t";
        cout << "年龄: " << abs->personArray[ret].m_Age << "\t";
        cout << "电话: " << abs->personArray[ret].m_Phone << "t";
        cout << "住址: " << abs->personArray[ret].m_Addr << endl;
    }
    else {
        cout << "查无此人" << endl;
    }
};

void modifyPerson(Addressbooks * abs){
    cout << "请输入您要修改的联系人: " << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1){
        // 姓名
        string name;
        cout << "请重新输入姓名: " << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;

        // 性别
        cout << "请重新输入性别: " << endl;
        cout << "1 --- 男 " << endl;
        cout << "2 --- 女 " << endl;
        int sex = 0;
        while (true){
            cin >> sex;
            if (sex == 1 || sex == 2)
                {
                    abs->personArray[ret].m_Sex = sex;
                    break;
                }
            cout << "输入有误，请重新输入" << endl;
        }

        // 年龄
        cout << "请重新输入年龄: " << endl;
        int age = 0;
        cin >> age;
        while (true)
        {
            if (age <= 0 || age > 100)
            {
                cout << "年龄输入有误， 请重新输入！" << endl;
                break;
            }
            abs->personArray[ret].m_Age = age;
            break;
        }

        // 电话
        cout << "请重新输入联系电话: " << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        // 地址
        cout << "请重新输入家庭住址: " << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr = address;

        cout << "修改成功！" << endl;
    }
    else {
        cout << "查无此人" << endl;
    }
};

// 清空联系人
void cleanPerson(Addressbooks * abs){
    abs->m_Size = 0;  // 逻辑清空即可清空联系人
    cout << "通讯录已清空" << endl;
};

void showMenu(){
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}


int main(){

    // 创建通讯录结构体变量
    Addressbooks abs;
    // 初始化通讯录中当前人员的个数
    abs.m_Size = 0;

    int select;

    while (true){
        // 显示菜单
        showMenu();
        cin >> select;
        switch (select)
        {
            case 1: // 1、添加联系人
                addPerson(&abs);  // 利用地址传递，可以修饰实参
                break;
            case 2: // 2、显示联系人
                showPerson(&abs);
                break;
            case 3: // 3、删除联系人
            // {
            //     cout << "请输入要删除的联系人姓名: "<< endl;
            //     string findName;
            //     cin >> findName;
            //     if (isExist(&abs, findName) == -1)
            //     {
            //         cout << "查无此人"<< endl;
            //     }
            //     else{
            //         cout << "找到了"<< endl;
            //     }
            // }
                deletePerson(&abs);
                break;
            case 4: // 4、查找联系人
                findPerson(&abs);
                break;
            case 5: //5、修改联系人
                modifyPerson(&abs);
                break;
            case 6: // 6、清空联系人
                cleanPerson(&abs);
                break;
            case 0: // 0、退出通讯录
                cout << "欢迎下次再使用～" << endl;
                return 0;
                // break;
            default:
                break;
        }
    }
    
    return 0;
}
