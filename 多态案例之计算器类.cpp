#include<iostream>
using namespace std;

/*

多态的优点：
    1、代码组织结构清洗
    2、可读性强
    3、利于前期和后期的扩展以及维护

开闭原则：
    对扩展进行开放，对修改进行关闭
*/

// 分别用普通写法和多态技术实现计算器

// 普通写法
class Calculator{
public:
    int m_Num1;
    int m_Num2;

    int getResult(string oper){
        if (oper == "+"){
            return m_Num1 + m_Num2;
        }
        else if (oper == "-"){
            return m_Num1 - m_Num2;
        }
        else if (oper == "*"){
            return m_Num1 * m_Num2;
        }
    };
};

void test01(){
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 5;
    cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
    cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
    cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
};

// 利用多态实现计算器

// 实现计算器的抽象类
class AbstractCalculator{
public:
    int m_Num1;
    int m_Num2;

    virtual int getResult(){
        return 0;
    };
};

// 加法计算器
class AddCalculator: public AbstractCalculator{
public:
    // 重写基类中的getResult()函数,
    // virtual 关键字可写可不写 
    virtual int getResult(){
        return m_Num1 + m_Num2;
    };
};

// 减法计算器
class SubCalculator : public AbstractCalculator
{
public:
    // 重写基类中的getResult()函数,
    // virtual 关键字可写可不写
    virtual int getResult()
    {
        return m_Num1 - m_Num2;
    };
};

// 乘法计算器
class MulCalculator : public AbstractCalculator
{
public:
    // 重写基类中的getResult()函数,
    // virtual 关键字可写可不写
    virtual int getResult()
    {
        return m_Num1 * m_Num2;
    };
};

void test02(){
    // 多态使用条件是：父类指针或者引用指向子类对象
    // 加法运算
    AbstractCalculator * abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
    // 用完记得销毁
    delete abc;

    // 减法运算
    abc = new SubCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
    // 用完记得销毁
    delete abc;

    // 乘法运算
    abc = new MulCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
    // 用完记得销毁
    delete abc;
};

int main(){

    // test01();
    test02();

    return 0;
}