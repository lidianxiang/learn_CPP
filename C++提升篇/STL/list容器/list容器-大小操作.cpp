#include<iostream>
using namespace std;
#include<list>

void printList(const list<int> &L){
    for(list<int>::const_iterator it=L.begin(); it!=L.end(); it++){
        cout << *it << "  ";
    }
    cout << endl;
}

void emptyList(list<int> &L){
    if(L.empty()){
        cout << "容器为空" << endl;
    }
    else{
        cout << "容器不为空" << endl;
        cout << "容器大小为: " << L.size() << endl;
    }
}

void test01(){

    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    printList(L1);

    emptyList(L1);

    // 重新指定容器size，默认以0填充
    L1.resize(10);
    printList(L1);


}


int main(){

    test01();

    return 0;
}