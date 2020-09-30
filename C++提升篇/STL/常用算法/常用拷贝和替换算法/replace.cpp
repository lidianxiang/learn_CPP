#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*

函数原型：
    replace_if(iterator_beg, iterator_end, oldValue newValue)  

*/

class MyPrint{
public:
    void operator()(int val){
        cout << val << " ";
    }

};

void test01(){

    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(10);
    v.push_back(20);
    v.push_back(20);

    cout << "替换前: " << endl;
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

    replace(v.begin(), v.end(), 20, 2000);

    cout << "替换后: " << endl;
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

}


int main(){

    test01();

    return 0;
}