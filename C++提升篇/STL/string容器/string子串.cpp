#include<iostream>
using namespace std;
#include<string>

void test01(){
    
    string str = "abcdefg";
    cout << "str = " << str << endl;
    string sub_str = str.substr(1, 3);
    cout << "sub_str = " << sub_str << endl;

    string email = "zhangsan@sina.com";
    int pos = email.find("@");
    string userName = email.substr(0, pos);
    cout << "UserName: " << userName << endl; 

};

int main(){

    test01();

    return 0;
}