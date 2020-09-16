#include<iostream>
using namespace std;
#include "person.hpp" 

/*

传统的分文件编写时，是将声明和实现分开编写，而在模版的分文件编写时，是将声明和实现
放在一起的，并约定俗成地命名为.hpp文件。

*/

void test01()
{
    Person<string, int> p("孙悟空", 100);
    p.showPerson();
};

int main()
{

    test01();
    return 0;
}