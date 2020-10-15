#include<iostream>
using namespace std;
#include "speechManager.h"
#include<cstdlib>
#include<ctime>

/*

比赛规则：
    1、学校举行一场演讲比赛，共有12个人参加。比赛分为两轮，第一轮是淘汰赛，第二轮是决赛
    2、每名选手都有对应的编号，如10001-10012
    3、比赛方式：分组比赛，每组6个人
    4、第一轮分为两个小组，整体按照选手编号进行抽签后顺序演讲
    5、十个评委分别给每个选手进行打分，去除最高分和最低分，求的是平均分为本轮选手的成绩
    6、当小组演讲完后，淘汰组内排名后三位，前三名晋级决赛
    7、第二轮为决赛，前三名胜出
    8、每轮比赛后需要显示选手的信息

程序功能：
    1、开始演讲比赛：完成整届比赛的流程，每个比赛阶段需要给用户一个提示，用户按任意键后继续下一个阶段
    2、查看往届记录：查看之前比赛前三名结果，每次比赛都会记录到文件中，文件用.csv后缀名保存
    3、清空比赛记录：将文件中数据清空
    4、退出比赛程序：可以退出当前程序

*/


int main(){

    // 创建随机数种子
    srand((unsigned int)time(NULL));

    SpeechManager sm;
    // // 测试代码
    // for(map<int,Speaker>::iterator it=sm.m_Speaker.begin(); it!=sm.m_Speaker.end(); it++){
    //     cout << "选手编号: " << it->first
    //          << "  姓名: " << it->second.m_Name
    //          << "  成绩: " << it->second.m_Score[0] << endl;
    // }

    int choice = 0; // 用来存储用户的选项

    while(true)
    {
        sm.show_Menu();

        cout << "请输入您的选择: " << endl;
        cin >> choice;  // 接受用户的选项

        switch(choice)
        {
        case 1:      // 开始比赛
            sm.startSpeech();
            break;
        case 2:      // 查看记录
            sm.showRecord();
            break;
        case 3:      // 清空记录
            sm.clearRecord();
            break;
        case 0:      // 退出系统
            sm.exitSystem();
            break;
        default:
            system("clear");  // 清屏
            break;
        }
    }

    // do
    // {
    //     cout << "Press the Enter key to continue.";
    // } while (cin.get() != '\n');

    return 0;
}