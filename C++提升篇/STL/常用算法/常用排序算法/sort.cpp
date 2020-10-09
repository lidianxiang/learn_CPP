#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*

常用的排序算法：
    1、sort
    2、random_shuffle
    3、merge
    4、reverse

sort算法：
    sort(iterator_beg, iterator_end, _Pred);  

*/

void myPrint(int val){
    cout << val << " ";
}

void test01(){

    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    sort(v.begin(), v.end());

    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

}


int main(){

    test01();

    return 0;
}