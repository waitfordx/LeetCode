#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

    bool is_match(const string s){
        stack<char> st;
        if(s[0] == ')') return false;
        if(s[0] == '(') st.push(s[0]);
        
        int len = 1;
        while(len < s.size())
        {
            if(s[len] == ')')
            {
                if(st.empty())
                    return false;
                st.pop();
            }     
            else if(s[len] == '(')
                st.push(s[len]);
            len++;
        }
        return st.empty() ? true : false;
    }

 string new_str(string s, int k){
        return s.erase(k, 1);
    }
          
    void recur_find(string s, vector<string>& res){
        if(s.empty()) return;
        vector<string> temp;
        string str;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == ')')
                str = new_str(s,i);
            else 
                continue;
            if(find(temp.begin(),temp.end(),str) == temp.end())
                temp.push_back(str);
            if(is_match(str) && find(res.begin(),res.end(),str) == res.end())
            {
                res.push_back(str);
                continue;
            }            
        }

       if(res.empty() && !temp.empty())
        {
            for(auto m : temp)
                recur_find(m, res);
        } 

    }

int main() {
    string str = "()(()((";
    vector<string> res;
    recur_find(str,res);
	for(auto m : res)
		cout<<m + "\t";
	return 0;
}