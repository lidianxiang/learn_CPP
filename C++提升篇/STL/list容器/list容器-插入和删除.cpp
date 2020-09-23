#include<iostream>
using namespace std;
#include<list>

/*

功能描述：对list容器进行数据的插入和删除

函数原型：
    1、push_back(elem);
    2、pop_back();
    3、push_front(elem);
    4、pop_front();
    5、insert(pos, elem);
    6、insert(pos, n, elem);
    7、insert(pos, beg, end);
    8、clear();
    9、erase(beg, end);
    10、erase(pos);
    11、remove(elem);  // 删除容器中所有与elem匹配的元素

*/

void printList(const list<int> &L){
    for(list<int>::const_iterator it=L.begin(); it!=L.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


void test01(){

    list<int> L;

    // 尾插
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);

    // 头插
    L.push_front(100);
    L.push_front(200);
    L.push_front(300);

    printList(L);

    // 尾删
    L.pop_back();
    printList(L);
    // 头删
    L.pop_front();
    printList(L);

    // insert插入
    L.insert(++L.begin(), 1000);
    printList(L);

    // 删除
    list<int>::iterator it = L.begin();
    L.erase(++it);
    printList(L);

}


int main(){

    test01();

    return 0;
}
