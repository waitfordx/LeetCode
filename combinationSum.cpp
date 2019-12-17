// 回溯算法 + 剪枝 求解 组合总和
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> candidates = {2,3,6,7};
vector<vector<int>> res;
vector<int> path;

// DFS 递归查找
void DFS(int start, int target)
{
    if(target == 0)
    {
        res.push_back(path);
        return;
    }
    for(int i = start; i < candidates.size() && target - candidates[i] >= 0; i++)
    {
        path.push_back(candidates[i]);
        DFS(i, target - candidates[i]);
        // 回溯到上一步
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    DFS(0, target);

    return res;
}

// (leetCode 39)
#if 0 
int main()
{
    int target = 7;
    res = combinationSum(candidates, target);
    for( auto m : res)
    {
        for(auto n : m)
            cout<<n<<"\t";
        cout<<endl;
    }
    return 0;
}
#endif


// leetCode 40 组合总数 2

class Solution {

private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            // 元素不可重复利用，使用下一个即i+1
            DFS(i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);
        return res;
    }
};