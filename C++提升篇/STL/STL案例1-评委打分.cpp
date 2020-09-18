#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>

/*

案例描述：
    有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分和最低分，取平均分

实现步骤：
    1、创建5名选手，放到vector中
    2、遍历vector容器，取出来每一个选手，执行for循环，可以把10个评委分存到deque容器中
    3、sort算法对deque容器中分数据排序，去除最高和最低分
    4、deque容器遍历一遍，累加总分
    5、获取平均分

*/

class Person{
public:

    Person(string name, int score){
        this->m_Name = name;
        this->m_Score = score;
    }

    string m_Name; // 姓名
    int m_Score;   // 分数
};

void createPerson(vector<Person> &v){

    string nameSeed = "ABCDE";

    for(int i=0; i<5; i++){
        string name = "选手";
        name += nameSeed[i];

        int score = 0;
        Person p(name, score);
        v.push_back(p);
    }

}

void setScore(vector<Person> &v){
    for(vector<Person>::iterator it=v.begin(); it!=v.end(); it++){
        // 将评委的分数放入到一个deque容器中
        deque<int> d;
        for(int i=0; i<10; i++){
            int score = rand() % 41 + 60;  // 随机打分，区间在60～100之间
            d.push_back(score);
        }

        // 显示出来
        // cout << "选手: " << it->m_Name << "  打分: " << endl;
        // for(deque<int>::iterator dit=d.begin(); dit!=d.end(); dit++){
        //     cout << *dit << "  ";
        // }
        // cout << endl;

        // 排序
        sort(d.begin(), d.end());

        // 去除最高分和最低分
        d.pop_front();
        d.pop_back();

        // 取平均分
        int sum = 0;
        for(deque<int>::iterator dit=d.begin(); dit!=d.end(); dit++){
            sum += *dit;
        }
        // 平均分
        int avg = sum / d.size();

        // 将平均分赋值给选手身上
        it->m_Score = avg;
    }
}

void showScore(vector<Person> &v){
    for(vector<Person>::iterator it=v.begin(); it!=v.end(); it++){
        cout << "姓名: " << (*it).m_Name << "  分数: " << (*it).m_Score << endl;
    }
}


int main(){

    // 添加随机数种子
    srand((unsigned int) time(NULL));

    // 1、创建5名选手
    vector<Person> v;
    createPerson(v);

    // 测试一下
    // for(vector<Person>::iterator it=v.begin(); it!=v.end(); it++){
    //     cout << "姓名: " << (*it).m_Name << " 分数: " << (*it).m_Score << endl;
    // }


    // 2、给5名选手打分
    setScore(v);

    // 3、显示最后得分
    showScore(v);

    return 0;
}