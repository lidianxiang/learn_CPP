#include<iostream>
using namespace std;
#include<set>

/*

利用仿函数，可以改变排序规则

*/

class MyCompare{

public:
    // 重载operator()操作运算符
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};

void printSet(set<int> &s){
    for(set<int>::iterator it=s.begin(); it!=s.end(); it++){
        cout << *it << "  ";
    }
    cout << endl;
}

void printSet2(set<int, MyCompare> &s){
    for(set<int, MyCompare>::iterator it=s.begin(); it!=s.end(); it++){
        cout << *it << "  ";
    }
    cout << endl;
}

void test01(){

    set<int> s1;
    s1.insert(10);
    s1.insert(50);
    s1.insert(20);
    s1.insert(40);
    s1.insert(30);

    printSet(s1);

    set<int, MyCompare> s2;
    s2.insert(10);
    s2.insert(50);
    s2.insert(20);
    s2.insert(40);
    s2.insert(30);
    printSet2(s2);
    
}


int main(){

    test01();

    return 0;
}
