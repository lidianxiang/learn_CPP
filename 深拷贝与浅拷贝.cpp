#include<iostream>
using namespace std;

/*

浅拷贝： 简单的赋值拷贝操作
如果使用浅拷贝会出现一个问题：就是在析构时会出现两次析构，第一次正常析构操作，完成指针地址的
正常释放，但是在进行第二次析构时，也会完成指针的地址释放，但是因为第一次已经释放完了就会出现报错。
深拷贝： 在堆区重新申请空间，进行拷贝操作

*/

class Person{
public:

    int m_Age;
    int *m_Height; // 创建一个指针数据

    Person(){
        cout << "无参构造函数调用" << endl;
    };

    Person(int age, int height){
        cout << "有参构造函数的调用" << endl;
        m_Age = age;
        // 使用new()操作后，在堆区创建一个地址，而不是栈区了
        m_Height = new int(height);
    };

    // 自己实现拷贝构造函数，解决浅拷贝带来的问题
    Person(const Person & p){
        cout << "拷贝构造函数的调用" <<endl;
        // 编译器会自动帮我们完成下面这两句代码
        m_Age = p.m_Age;
        // m_Height = p.height; // 编译器会自动帮我们完成下面这句代码
        /* 深拷贝操作
        这里之所以编译器不帮你自动复制的原因时因为栈区有系统的内存管理，
        而堆区没有（结束之前），所以需要你自己造轮子来拷贝
        */
        m_Height = new int(*p.m_Height);
    };

    ~Person(){
        // 析构代码，将堆区开辟的数据进行释放
        if (m_Height != NULL){
            delete m_Height;
            m_Height = NULL;  // 防止成为野指针
        }
        cout << "析构函数的调用"<< endl;
    };


};

void test01(){
    Person p1(18, 160);
    cout << "p1的年龄为: " << p1.m_Age  << "  身高为: " << *p1.m_Height << endl;

    Person p2(p1);
    cout << "p2的年龄为: " << p2.m_Age << "  身高为: " << *p2.m_Height << endl;

};

int main(){

    test01();

    return 0;
}