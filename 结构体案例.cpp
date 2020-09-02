#include<iostream>
using namespace std;

//定义一个英雄结构体
struct Hero{
    string name;
    int age;
    string sex;
};

// 冒泡排序
void bubbleSort(struct Hero heroArray[], int len){
    for (int i=0; i < len - 1; i++){
        for (int j=0; j < len - 1 - i; j++){
            if (heroArray[j].age > heroArray[j+1].age){
                struct Hero temp = heroArray[j];
                heroArray[j] = heroArray[j+1];
                heroArray[j+1] = temp;
            }
        }
    }
}


// 打印排序后的数组信息
void printHero(struct Hero heroArray[], int len){
    for (int i=0; i < len; i++){
        cout << "姓名: " << heroArray[i].name 
             << " 年龄: " << heroArray[i].age
             << " 性别: " << heroArray[i].sex
             << endl;
    }
}

int main(){
    struct Hero heroArray[5] =
    {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 19, "女"},

    };
    int len = sizeof(heroArray) / sizeof(heroArray[0]);
    // for (int i=0; i < len; i++){
    //     cout << heroArray[i].name << endl;
    // }
    bubbleSort(heroArray, len);
    printHero(heroArray, len);
    return 0;
}