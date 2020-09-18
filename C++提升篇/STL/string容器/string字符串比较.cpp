#include<iostream>
using namespace std;
#include<string>

void test01(){
    string str1 = "hello";
    string str2 = "hello";
    string str3 = "xello";

    if (str1.compare(str2) == 0){
        cout << "str1 等于 str2" << endl;
    }

    if (str3.compare(str1) > 0){
        cout << "str1 大于 str3" << endl;
    }

};

int main(){

    test01();

    return 0;
}