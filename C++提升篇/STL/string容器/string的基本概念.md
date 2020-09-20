### string的基本概念

**本质**:

+ string是C++风格的字符串，而string本质是一个lei

**string和char * 区别**:

+ char * 是一个指针
+ string是一个类，类的内部封装了char *，管理这个字符串是一个char * 型的容器

**特点**:

+ string类内部封装了很多成员方法
+ 例如：查找find、拷贝copy、删除delete、替换replace、插入insert
+ string管理char * 所分配的内存，不用担心复制越界和曲直越界等，由类内部进行负责



### string构造函数

构造函数原型：

+ string();                                     // 创建一个空的字符串，例如 string str;
+ string(const char* s);             // 使用字符串s初始化
+ string(const string& str);       // 使用一个string对象初始化另一个string对象
+ string(int n,  char c);               // 使用n个字符c初始化 