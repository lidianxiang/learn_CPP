#include<iostream>
using namespace std;

void bubbleSort(int * arr, int len){
    for (int i=0; i<len - 1; i++){
        for (int j=0; j<len - 1 - i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int * arr, int len){
    for (int i=0; i<len; i++){
        cout << arr[i] <<endl;
    }
}


int main()
{
    //定义一个乱序数组
    int arr[10] = {4,3,6,9,1,2,10,8,7,5};
    // 求出数组的长度
    int len = sizeof(arr) / sizeof(arr[0]);
    //冒泡排序
    bubbleSort(arr, len);
    cout << "打印排序后的数组: " << endl;
    //打印数组
    printArray(arr, len);
    return 0;
}