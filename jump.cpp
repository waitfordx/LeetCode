// LeetCode 45 跳跃游戏 2 
/* 给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

// 深度、广度优先搜索超出时间限制，需要剪枝
/* set<int> res;
void my_dfs(vector<int>& nums, int target, int index, int step)
{
    if(index == target) 
    {
        res.insert(step);
        return;
    }
    int stride = nums[index];
    for(int i = 1; i <= stride; i++)
    {
        if(i + index > target) continue;
        my_dfs(nums, target, index+i, step+1);
    }
} */

/* set<int> visit;
int my_bfs(vector<int>& nums, int target)
{
    int step = 0;
    queue<int> que;
    int root = 0;
    que.push(root);
    while(!que.empty())
    {
        int count = que.size();
        step++;
        for(int c = 0; c < count; c++)
        {
            int index = que.front();
            que.pop();
            int stride = nums[index];
            for(int i = 1; i <= stride; i++)
            {
                int next_index = i + index;
                if(visit.count(next_index) != 0) continue;
                if(next_index == target) return step;
                visit.insert(next_index);
                que.push(next_index);
            } 
        }
    }
    return step;
} */

// 贪心算法
int jump(vector<int> &nums)
{
    int ans = 0;
    int end = 0;
    int maxPos = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        maxPos = max(nums[i] + i, maxPos);
        if (i == end)
        {
            end = maxPos;
            ans++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {2,3,1,1,4};
    int res = jump(nums);
    cout<< res;
    return 0;
}
