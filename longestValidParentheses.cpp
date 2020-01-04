// 求最长有效括号
#include <vector>
#include <stack>
#include <string>

using namespace std;

/* 暴力法解决
** 对于给定的字符串中所有可能的偶数非空字符串，判断它是否是一个有效字符串
** 用栈来进行辅助判断，并记录最长长度
** 超出内存限制
*/
bool isValid(string str)
{
    stack<char> sc;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')
            sc.push('(');
        else if(!sc.empty() && sc.top() == '(')
        {
            sc.pop();
        }
        else
        {
            return false;
        }
    }    
    return sc.empty();    
}

int longestValidParentheses(string s)
{
    int max_len = 0;
    for(int i = 0; i < s.length(); i++)
    {
        for(int j = 2; i+j <= s.length(); j+= 2)
        {
            string str = s.substr(i, j);
            if(isValid(str))
                max_len = max(max_len, j);
        }
    }
    return max_len;
}


/* 动态规划解决
** 定义一个数组 dp[] , dp[i] 表示以下标 i 结尾的有效子字符串的长度
** 有效的子字符串一定以 ‘）’ 结尾，只需要更新 ‘）’在 dp 数组中对应位置的值
** 1. s[i] == ')' 且 s[i-1] == '(' :                            dp[i] = dp[i-2] + 2
** 2. s[i] == ')' 且 s[i-1] == ')' 如果 s[i-dp[i-1]-1] == '(' : dp[i] = dp[i-1] + dp[i-dp[i-1]-2] +2
*/
int longestValidParentheses(string s)
{
    int max_res = 0;
    int dp[s.length()] = {0};

    for(int i = 1; i < s.length(); i++)
    {
        if(s[i] == ')')
        {
            // 当前的 ）与它前面的（ 相匹配
            if(s[i-1] == '(')
            {
                dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
            } 
            else if(i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(')
            {
                 dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
        }
        max_res = max(max_res, dp[i]);
    } 
    return max_res;
}

/* 用栈在遍历的过程中检查子字符串的有效性
** 首先将-1放入栈顶
** 对于每一个遇到的 ‘（ ’ 入栈
** 对于每一个遇到的 ‘]’ 弹出一个元素
** 并计算2个下标之差
*/
int longestValidParentheses(string s)
{
    int max_res = 0;
    stack<int> sc;
    sc.push(-1);
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            sc.push(i);
        }
        else
        {
            sc.pop();
            // 栈为空时， -1 被出栈，有一个 ‘）’未被匹配，有效字符串被打断 入栈该下标，
            if(sc.empty())
            {
                sc.push(i);
            }
            else
            {
                max_res = max(max_res, i-stack.top());
            }
        }
    }
    return max_res;
}