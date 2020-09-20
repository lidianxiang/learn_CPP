#include<iostream>
using namespace std;
#include<vector>

/*

函数原型：
    1、empty();      // 判断容器是否为空
    2、capacity();    // 容器的容量
    3、size();        // 返回容器中元素的个数
    4、resize(int num);   // 重新指定容器的长度为num个，若容器变长，则以默认值填充新的位置
                          若容器变短，则以末尾超出容器的重读的元素被删除
    5、resize(int num, elem); // 重新指定容器的长度为num个。若容器变长，则以elem值填充位置
                                如果容器变短，则以末尾超出容器的长度的元素被删除

*/

void printVector(vector<int> &v){
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void vectorEmpty(vector<int> &v){
    if (v.empty()){
        cout << "vector is empty!" << endl;
    }
    else {
        cout << "vector is not empty!" << endl;
        cout << "vector capacity: " << v.capacity() << endl;
        cout << "vector size: "<< v.size() << endl;
    }
}

void test01(){
    vector<int> v1;
    for(int i=0; i<10; i++){
        v1.push_back(i);
    };
    printVector(v1);
    vectorEmpty(v1);  // 判断vector容器是否为空

    // resize操作
    v1.resize(17);
    printVector(v1);  // 默认以0填充
    cout << "v1 capacity: " << v1.capacity() << endl;

    
};

int main(){

    test01();

    return 0;
}