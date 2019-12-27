/* 删除排序数组中的重复项 
** 快慢指针法
*/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    if(len <= 2) return len;

    int slow = 1;
    for(int fast = 2; fast < len; fast++)
    {
        if(nums[fast] != nums[slow-1])
        {
            nums[++slow] = nums[fast];
        }
    }
    return slow+1;
}

#if 1

int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    int res = removeDuplicates(nums);
    for(int i = 0; i < res; i++)
        cout<<nums[i]<<"\t";
    return 0;
}

#endif