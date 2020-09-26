#include<iostream>
using namespace std;
#include<map>

/*

map容器默认排序规则为按照key值进行从小到大排序，可以使用仿函数来改变排序规则

*/

class MyCompare{
public:
    bool operator()(int v1, int v2){
        // 降序
        return v1 > v2;
    }
};


void test01(){

    map<int, int, MyCompare> mp;
    mp.insert(make_pair(1,10));
    mp.insert(make_pair(5,50));
    mp.insert(make_pair(3,30));
    mp.insert(make_pair(4,40));
    mp.insert(make_pair(2,20));

    for(map<int, int, MyCompare>::iterator it=mp.begin(); it!=mp.end(); it++){
        cout << "key = " << it->first << ", value = " << it->second << endl;
    }
    cout << endl;

}


int main(){

    test01();

    return 0;
}