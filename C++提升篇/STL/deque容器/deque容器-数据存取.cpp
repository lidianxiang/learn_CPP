#include<iostream>
using namespace std;
#include<deque>

void printDeque(const deque<int> d){
    for(deque<int>::const_iterator it=d.begin(); it!=d.end(); it++){
        cout << *it << "  ";
    }
    cout << endl;
}


void test01(){

    deque<int> d1;
    for(int i=0;i < 10; i++){
        d1.push_back(i);
        d1.push_front(i);
    }
    printDeque(d1);

    // 获取数据
    cout << "d1的第2个数据: " << d1.at(1) << endl;
    cout << "d1的第6个数据: " << d1[5] << endl;
    cout << "d1的第一个数据: " << d1.front() << endl;
    cout << "d1的最后一个数据: " << d1.back() << endl;
}


int main(){
    test01();

    return 0;
}