// c++ 常用库函数的实现
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <assert.h>

using namespace std;

// 翻转字符串
void strRev(char *s)
{
    char temp, *end = s + strlen(s) - 1;
    while(end > s)
    {
        temp = *s;
        *s = *end;
        *end = temp;
        --end;
        ++s;
    }
}

// 库函数 strcpy 位于 string.h 中
char* strcpy(char* dest, const char* src)
{
    // 检查空指针
    assert(dest != NULL && src != NULL);

    // 返回目标地址
    char* pdest = dest;
    const char* psrc = src;
    
    // 拷贝最后的 '\0'
    while((*pdest++ = *psrc++) != '\0')
        ;
    // 返回 char* 支持链式表达式
    return dest;
}

// 消除内存重叠的 strcpy, 实现 char* 版本的 memcpy  
// void * memcpy ( void * destination, const void * source, size_t num );

char* my_memcpy(char* dst, const char* src, int num)
{
    if(dst == NULL || src == NULL) return NULL;

    char* dest = dst;
    const char* src1 = src;

    // 自高位向低位开始拷贝， 解决内存重叠问题
    if(dest > src1 && dest < src1 + num)
    {
        dest += (num-1);
        src1 += (num-1);
        while(num--)
            *dest-- = *src1--;
    }
    else
    {
        while(num--)
            *dest++ = *src1++;
    }
    return dst;
}

char* my_strcpy(char* dest, const char* src)
{
    // 检查空指针
    assert(dest != NULL && src != NULL);

    // 返回目标地址
    char* res = dest;

    // C函数 memcpy 自带内存重叠检测功能
    my_memcpy(res, src, strlen(src)+1);
    
    // 返回 char* 支持链式表达式
    return dest;
}

int main()
{
    const char* src = "this is a test";
    char* p = new char(15);
    strcpy(p, src);
    cout<<p;
    delete p;
    return 0;  
}