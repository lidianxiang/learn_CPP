#include<iostream>
using namespace std;
#include<queue>

/*

概念： queue是一种先进先出的数据结构，它有两个出口

    队列容器允许从一端新增数据，从另一端移除数据，队列中只有队头和队尾可以被外界访问，不允许遍历行为。
队列中进数据称为：入队 push
队列中出数据称为：出队 pop

常用接口：
    1、构造函数
        1.1 queue<T> que;
        1.2 queue(const queue &que);
    2、赋值操作
        2.1 queue& operator=(const queue &que);
    3、数据存取
        3.1 push(elem);
        3.2 pop();
        3.3 back();
        3.4 front();
    4、大小操作
        4.1 empty();
        4.2 size();

*/

class Person{
public:
    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    };

    string m_Name;
    int m_Age;

    ~Person(){};
};


void test01(){
    queue<Person> q;

    Person p1("唐僧", 30);
    Person p2("孙悟空", 1000);
    Person p3("猪八戒", 900);
    Person p4("沙僧", 800);

    // 入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    cout << "queue size: " << q.size() << endl << endl;

    while(!q.empty()){
        cout << "队头元素 --- 姓名: " << q.front().m_Name << " 年龄: " << q.front().m_Age << endl;
        cout << "队尾元素 --- 姓名: " << q.back().m_Name << " 年龄: " << q.back().m_Age << endl;
        cout << endl;

        q.pop();
    }

    cout << "queue size: " << q.size() << endl;

}


int main(){

    test01();

    return 0;
}