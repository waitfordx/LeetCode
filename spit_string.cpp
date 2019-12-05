// 实现一个 c++ 字符串分割函数
// c 库函数  char* strtok(char* str, const char* delim), 需要更新

#include <vector>
#include <string>
#include <iostream>

using namespace std;

// 字符串分割  
vector<string> spit_string(const string str, const string delim)
{
    vector<string> v;
    string::size_type cur_pos, start_pos;
    cur_pos = str.find(delim);
    start_pos = 0;
    while(cur_pos != string::npos)
    {
        v.push_back(str.substr(start_pos, cur_pos-start_pos));
        start_pos = cur_pos + delim.size();
        cur_pos = str.find(delim, start_pos);
    }
    if(start_pos != str.size())
        v.push_back(str.substr(start_pos));

    return v;
}

int main()
{
// 字符串分割  
    const string str = "this.is.a.test.string";
    const string delim = ".";
    vector<string> v;
    v = spit_string(str, delim);
    for(auto s : v)
        cout<< s <<endl; 



    string str = "thia ia the teat atring";
    size_t pos = str.find("a");
    while(pos != string::npos)
    {
        str.replace(pos, 1, "s");
        
    }
    
    cout<<str; 
    return 0;
}