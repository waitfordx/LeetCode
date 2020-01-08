// 通过全排列理解回溯算法 深度优先遍历 状态重置 剪枝
/* 1. 路径: 已经做出了的选择
** 2. 选择列表：当前可以做的选择
** 3. 结束条件：到达决策树的底层
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 求一个数组的全排列（数字不重复） eg:{1,2,3}
class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<int> v;
        this->nums = nums;
        traceback(v, 0);
        return res;
    }
private:
    vector<vector<int> > res;
    vector<int> nums;
    void traceback(vector<int>&v, int step)
    {
        // 结束条件
        if(step == nums.size())
        {
            res.push_back(v);
            return;
        }
        step++;
        // 选择列表
        for(int i = 0; i < nums.size(); i++)
        {
            if(find(v.begin(), v.end(), nums[i]) == v.end())
            {
                // 选择符合条件的加入路径中
                v.push_back(nums[i]);
                // 进行递归
                traceback(v, step);
                // 恢复现场(回溯)
                v.pop_back();                
            }
        }
    }
};

// 求一个数组的全排列（数字可以重复） eg:{1,1,2}, 因为有重复数字，需要剪枝
class Solution{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<int> v;
        vector<bool> visit(nums.size(), false);
        // 为了去除，需要先排序
        sort(nums.begin(), nums.end());
        this->nums = nums;
        traceback(v, visit, 0);
        return res;
    }
private:
    vector<vector<int> > res;
    vector<int> nums;
    void traceback(vector<int>&v, vector<bool>& visit, int step)
    {
        // 结束条件
        if(step == nums.size())
        {
            res.push_back(v);
            return;
        }
        step++;
        // 选择列表
        for(int i = 0; i < nums.size(); i++)
        {
            // 已经被选择的数字， 跳过
            if(!visit[i]) continue;
            // 遇到重复数字，且前面相同的数组也未被放入路径中，则跳过该数字（因为可以取前面的值）
            if(i > 0 && nums[i] == nums[i-1] && !visit[i-1]) continue;
            // 选择符合条件的加入路径中，并标记
            v.push_back(nums[i]);
            visit[i] = true;
            // 进行递归
            traceback(v, visit, step);
            // 恢复现场(回溯)
            v.pop_back();     
            visit[i] = false;           
        }
    }
};

// 求一个数组的全排列（数字可以重复） eg:{1,1,2}, 因为有重复数字，需要剪枝
// 利用 map 来去重
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->nums = nums;
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<int> v;
        trace_back(v, mp, 0);
        return this->res;
    }
private:
    vector<vector<int> > res;
    vector<int> nums;
    void trace_back(vector<int>& v, map<int, int>&mp, int step)
    {
        if(step == nums.size())
        {
            res.push_back(v);
            return;
        }
        step++;
        for(auto &p : mp)
        {
            if(p.second == 0) continue;
            p.second--;
            v.push_back(p.first);
            trace_back(v,mp,step);
            p.second++;
            v.pop_back();
        }
    }
};