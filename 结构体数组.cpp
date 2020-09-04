#include<iostream>
using namespace std;

struct Student
{
    /* data */
    string name;
    int age;
    float score;
};


int main(){
    struct Student stuArray[] = {
        {"张三" , 18 ,55.3},
        {"李四" , 28, 13.5},
        {"王虎" , 38, 53.2},
    };
    for (int i=0; i < 3; i++){
        cout << "name: "  << stuArray[i].name 
             << " age: "  << stuArray[i].age 
             << " score: "<< stuArray[i].score
             << endl;
        
    };
    return 0;

}
