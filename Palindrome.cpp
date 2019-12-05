#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <algorithm>

using namespace std;



// 前缀树的声明与定义
struct TrieNode{
    TrieNode* child[26];
    vector<int> words;
    vector<int> suffixs;
    TrieNode(){
        memset(child, NULL, sizeof(child));
    }
};

TrieNode* root;

// 判断一个字符串是否回文对
bool isPalindrom(string s)
{
    int i = 0, j = s.size()-1;
    while(i < j)
        if(s[i++] != s[j--])
            return false;
    return true;
}

// 构造字典树(逆序放入树上)
void build_Trie(vector<string>& words)
{
    root = new TrieNode();
    int len = words.size();
    for(int i = 0; i < len; i++)
    {
        TrieNode* cur = root;
        string str = words[i];
        reverse(str.begin(), str.end());
        if(isPalindrom(str)) cur->suffixs.push_back(i);
        for(int j = 0; j < str.size(); j++)
        {
            char ch = str[j];
            if(cur->child[ch-'a'] == NULL) cur->child[ch-'a'] = new TrieNode();
            cur = cur->child[ch-'a'];
            if(isPalindrom(str.substr(j+1))) cur->suffixs.push_back(i);
        }
        cur->words.push_back(i);
    }
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int> > res;
    int len = words.size();
    build_Trie(words);
    for(int i = 0; i < len; i++)
    {
        string str = words[i];
        TrieNode* cur = root;
        int j = 0;
        for(; j < str.size(); j++)
        {
            if(isPalindrom(str.substr(j)))
                for(int k : cur->words)
                    if(k != i) res.push_back(vector<int> {i, k});
            
            char ch = str[j];
            if(cur->child[ch-'a'] == NULL) break;
            cur = cur->child[ch-'a'];
        }
        if(j == str.size())
            for(int k : cur->suffixs)
                if(k != i) res.push_back(vector<int> {i,k});
    }
    return res;      
}

int main()
{
    vector<string> words = {"abcd","dcba","lls","s","sssll"};
    vector<vector<int >>res;
    res = palindromePairs(words);
    for(auto k : res)
    {
        for(auto m : k)
            cout<<m<<"\t";
        cout<<endl;
    }
    return 0;
}