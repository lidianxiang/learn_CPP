#include<iostream>
using namespace std;

int main(){
    /*常量指针的特点：
    指针的值向可以修改，但是指针指向的值不可以修改
    */
   int a = 10;
   int b = 10;
   const int * p = &a;
   //常量指针可以更改地址，例如此时指向了b
   p = &b;

   /*
   指针常量的特点：
   指针指向的值可以修改，但是指针的指向不可以修改
   */
    int * const p2 = &a;
    //指针常量的值是可以被修改的
    *p2 = 20;
    /*
    const既修饰指针又修饰常量的特点：
    指针的指向和指针的值都不可以修改
    */
   const int * const p3 = &a;
   return 0;
}