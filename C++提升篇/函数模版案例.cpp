#include<iostream>
using namespace std;

/*

案例描述：
    1、利用函数模版封装一个排序的函数，可以对于不同的数据类型数组进行排序
    2、排序规则从大到小，排序算法为选择排序
    3、分别利用char数组和int数组进行测试

*/

// 交换模版
template<class T>
void mySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
};


// 选择排序的模版 
template<class T>
void mySort(T arr[], int len){
    for (int i=0; i < len; i++){
        int max = i; // 初始化时，设置最大数的下标为i
        for (int j=i+1; j < len; j++){
            if (arr[max] < arr[j]){ // 判断
                max = j; // 条件符合时将最大下标改为j
            }
        }
        if (max != i){
            mySwap(arr[max], arr[i]); // 交换两个数
        }
    }
};

// 打印数据的模版
template<class T>
void printArray(T arr[], int len){
    for (int i=0; i< len; i++){
        cout << arr[i] << " ";
    };
    cout << endl;
};


void test01(){
    char charArr[] = "cdfbae";
    int length = sizeof(charArr) / sizeof(char);
    mySort(charArr, length);
    printArray(charArr, length);
};

void test02(){
    int intArr[] = {9,1,4,5,3,7,2,8,6};
    int length = sizeof(intArr) / sizeof(int);
    mySort(intArr, length);
    printArray(intArr, length);
};

int main(){

    test01();

    test02();

    return 0;
}