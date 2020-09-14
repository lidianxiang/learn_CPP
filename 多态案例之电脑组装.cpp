#include<iostream>
using namespace std;

/*

案例描述：
    电脑主要组成部件为CPU、显卡、内存条，将每个每个零件封装出抽象基类，并且提供不同厂商
    生产的不同的零件，例如Inter厂商和Leveno厂商，创建电脑类提供让电脑工作的函数，并且
    调用每个零件工作的接口，测试时组装三台不同的电脑进行工作

*/

// CPU类
class CPU{
public: 
    virtual void calculate() = 0;
};

// 内存条类
class Memory
{
public:
    virtual void storage() = 0;
};

// 显卡类
class VideoCard
{
public:
    virtual void display() = 0;
};

// 电脑类
class Computer{
public:
    // 构造函数
    Computer(CPU *cpu, VideoCard *vc, Memory *mem){
        m_cpu = cpu;
        m_vc = vc; 
        m_mem = mem;
    };

    void work(){
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    };

    ~Computer(){
        if (m_cpu != NULL){
            delete m_cpu;
            m_cpu = NULL;
        };

        if (m_vc != NULL)
        {
            delete m_vc;
            m_vc = NULL;
        };

        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        };
    };

private:
    CPU *m_cpu; // cpu零件指针
    VideoCard *m_vc;  // 显卡零件指针
    Memory *m_mem;  // 内存条零件指针
};


// 具体厂商
class InterCPU: public CPU{
public:
    virtual void calculate(){
        cout << "Inter的CPU开始计算了..." << endl;
    };
};

class InterVideoCard : public VideoCard
{
public:
    virtual void display()
    {
        cout << "Inter的显卡开始显示了..." << endl;
    };
};

class InterMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "Inter的内存条开始存储了..." << endl;
    };
};

// Lenove厂商
class LenoveCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "Lenove的CPU开始计算了..." << endl;
    };
};

class LenoveVideoCard : public VideoCard
{
public:
    virtual void display()
    {
        cout << "Lenove的显卡开始显示了..." << endl;
    };
};

class LenoveMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "Lenove的内存条开始存储了..." << endl;
    };
};

void test01(){
    //第一台电脑
    CPU * interCpu = new InterCPU;
    VideoCard * interCard = new InterVideoCard;
    Memory * interMem = new InterMemory;

    // 创建第一台电脑
    cout << "第一台电脑开始工作了..." << endl;
    Computer *computer1 = new Computer(interCpu, interCard, interMem);
    computer1->work();
    delete computer1;

    // 创建第二台电脑
    cout << "--------------------------" << endl;
    cout << "第二台电脑开始工作了..." << endl;
    Computer *computer2 = new Computer(new LenoveCPU, new LenoveVideoCard, new LenoveMemory);
    computer2->work();
    delete computer2;

    // 创建第二台电脑
    cout << "--------------------------" << endl;
    cout << "第三台电脑开始工作了..." << endl;
    Computer *computer3 = new Computer(new LenoveCPU, new InterVideoCard, new LenoveMemory);
    computer3->work();
    delete computer3;
};

int main(){

    test01();

    return 0;
}