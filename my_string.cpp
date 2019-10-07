// 自定义字符串的实现 构造函数 拷贝构造函数 赋值运算符重载 析构函数
#include <stdio.h>
#include <string.h>

using namespace std;

class my_string
{
private:
    char* ptr;
public:
    // 构造函数,
    my_string(const char* p = nullptr)
    {
        if(p == nullptr)
        {
            // 声明一个大小为 1 的 char 数组,空指针时，放置一个 '/0' 标志位
            ptr = new char[1];
            *ptr = '\0';
        }
        else
        {
            ptr = new char(strlen(p) + 1);
            strcpy(ptr, p);
        }
    }

    // 拷贝构造函数
    my_string(const my_string& other)
    {
        ptr = new char(strlen(other.ptr)+1);
        strcpy(ptr, other.ptr);
    }

    // 重载默认运算符 =
    my_string& operator= (const my_string& other)
    {
        // other 是一个 const 类型变量， 不能与 *this 比较、 但是 &other 是一个普通指针可以与 this 比较
        if(this != &other)
        {
            char* temp = new char(strlen(other.ptr) + 1);
            strcpy(temp, other.ptr);
            delete [] ptr;
            ptr = temp;
        }
        return *this;
    }

    // 析构函数
    ~my_string()
    {
        if(ptr)
            delete [] ptr;
    }
};

int main()
{
    my_string a("abc");
    return 0;
}