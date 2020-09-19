#include<iostream>
using namespace std;
#include<vector>
/*

实现两个容器内元素进行互换

函数原型：
    swap(vec);   // 将vec与本身进行互换

*/

void printVector(vector<int> &v){
    for(vector<int>::iterator it=v.begin(); it != v.end(); it ++){
        cout << *it << " " ;
    }
    cout << endl;
}


void test01(){

    vector<int> v1;

    for(int i=0; i<10; i++){
        v1.push_back(i);
    };
    cout << "交换前: " << endl;
    printVector(v1);

    vector<int> v2;
    for(int i=10; i>0; i--){
        v2.push_back(i);
    }
    printVector(v2);

    cout << "交换后: " << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);

}

//swap()函数的用途
void test02(){

    vector<int> v;

    for(int i=0; i<100000; i++){
        v.push_back(i);
    }

    cout << "v的容量: " << v.capacity() << endl;  // 131072
    cout << "v的大小: " << v.size() << endl;      // 100000

    // 重新指定v的大小
    v.resize(3);
    cout << "v的容量: " << v.capacity() << endl;   // 131072
    cout << "v的大小: " << v.size() << endl;       // 3

    // 巧用swap来收缩内存
    // vector<int>(v)为匿名对象，将原数据与匿名对象进行交换，匿名对象执行后会被系统自动清除内存
    vector<int>(v).swap(v);
    cout << "v的容量: " << v.capacity() << endl;   // 3
    cout << "v的大小: " << v.size() << endl;       // 3
}

int main(){
    
    // test01();
    test02();

    return 0;
}