#include<iostream>
using namespace std;
#include<functional>
#include<algorithm>
#include<vector>

/*

功能：实现关系对比

仿函数原型：
    1、template<class T> bool equal_to<T>
    2、template<class T> bool not_equal_to<T>
    3、template<class T> bool greater<T>
    4、template<class T> bool greater_equal<T>
    5、template<class T> bool less<T>
    6、template<class T> bool less_equal<T>

*/

void printVector(vector<int> &v){
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout << *it << "  ";
    }
    cout << endl;
}

class MyCompare{
public: 
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};

void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    printVector(v);

    // sort(v.begin(), v.end(), MyCompare());
    sort(v.begin(), v.end(), greater<int>());

    printVector(v);


}


int main(){

    test01();

    return 0;
}