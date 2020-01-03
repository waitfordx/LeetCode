// 利用滑动窗口解决字符串匹配问题

#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words)
{
    if(s.empty() || words.empty()) return {};
    vector<int> ret;
    // 单词长度， 单词个数以及窗口最大长度
    int word_len = words[0].size();
    int word_num = words.size();
    int window_len = word_len * word_num;
    // 建立单词与个数的映射
    map<string, int> mp;
    for(const string& str : words) mp[str]++;
    // 开始扫描
    for(int i = 0; i < word_len; i++)
    {
        unordered_map<string, int> ump;
        // 窗口的左右边界和匹配的单词个数
        int left = i, right = i, count = 0;
        // 开始滑动窗口
        while(right+word_len <= s.size())
        {
            // 提取一个单词，并扩大窗口
            string w = s.substr(right, word_len);
            right += word_len;
            // 未匹配单词，重置状态
            if(mp.count(w) == 0)
            {
                left = right;
                count = 0;
                ump.clear();
            }
            else
            {
                ump[w]++;
                count++;
                // 匹配的单词数大于 words 中的单词数，有单词出现了多次，缩小窗口
                while(ump.at(w) > mp.at(w))
                {
                    string t_w = s.substr(left, word_len);
                    ump[t_w]--;
                    count--;
                    left += word_len;
                }
                if(count == word_num) ret.push_back(left);
            }
        }
    }
    return ret;
}


int main()
{
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> res;
    res = findSubstring(s, words);
    for(auto i : res)
        cout<<i<<'\t';

    return 0;
}