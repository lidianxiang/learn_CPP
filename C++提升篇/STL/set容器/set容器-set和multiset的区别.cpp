#include<iostream>
using namespace std;
#include<set>

/*

区别：
    1、set不可以插入重复的数据，而multiset可以
    2、set插入数据的同时会返回插入的结果，表示插入是否成功
    3、multiset不会检测数据，因此可以插入重复的数据

*/

void printMultiset(multiset<int> &mt){
    for(multiset<int>::iterator it=mt.begin(); it!=mt.end(); it++){
        cout << *it << "   ";
    }
    cout << endl;
}

void test01(){

    set<int> s1;
    // set的insert()函数实际上是一种叫pair的数据类型，第一个值是迭代器，第二个值是bool类型
    pair<set<int>::iterator, bool> ret = s1.insert(10);
    if (ret.second){
        cout << "第一次插入成功了" << endl;
    }
    else{
        cout << "第一次插入失败了" << endl;
    }

    ret = s1.insert(10);
    if (ret.second)
    {
        cout << "第二次插入成功了" << endl;
    }
    else
    {
        cout << "第二次插入失败了" << endl;
    }


    // multiset类型
    multiset<int> mt;
    mt.insert(10);
    mt.insert(10);
    mt.insert(10);
    mt.insert(10);

    printMultiset(mt);
}


int main(){

    test01();

    return 0;
}