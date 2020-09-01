#include<iostream>
using namespace std;

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    cout << "数组中的第一个元素: " << arr[0]<< endl;
    //指针指向数组名，即表示指针指向了数组的首地址
    int * p = arr;
    cout << "利用指针得到的数组的第一个元素: "<< *p << endl;
    p++; //指针向后偏移了4个字节
    cout << "指针指向数组的第二个元素: "<< *p << endl;
    cout << "利用指针来遍历数组: "<< endl;
    int * p2 = arr;
    for (int i=0; i<10; i++){
        // cout << arr[i]<< endl;
        // cout << *p2 << endl;
        // p2++;
        cout << *p2++ <<endl;
    }
    return 0;
}