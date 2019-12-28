/* 搜索旋转排序数组 II 
** 先查找到旋转后的分界点
** 进行两次二分查找
*/

#include <iostream>
#include <vector>

using namespace std;

 bool search(vector<int>& nums, int target) {
    if(nums.size() < 1) return false;
    // 找到旋转后的分界点 index
    int len = nums.size() - 1;
    int index = 0;
    for(int i = 0; i < len; i++)
    {
        if(nums[i] <= nums[i+1])
            index++;
        else
            break;
    }
    // 进行两次二分查找， 查找左边
    int left1 = 0, right1 = index;
    while(left1 <= right1)
    {
        int mid = left1  + (right1-left1)/2;
        if(target == nums[mid]) return true;
        if(target > nums[mid])
        {
            left1 = mid + 1;
        }
        else
        {
            right1 = mid - 1;
        }
    }
    // 查找右边
    int left2 = index+1, right2 = len;
    while(left2 <= right2)
    {
        int mid = left2  + (right2-left2)/2;
        if(target == nums[mid]) return true;
        if(target > nums[mid])
        {
            left2 = mid + 1;
        }
        else
        {
            right2 = mid - 1;
        }            
    }
    return false;
}

int main()
{
    vector<int> nums = {2,5,6,0,0,1,2};
    bool flag = search(nums, 0);
    if(flag)
    {
        cout<< "true";
    }
    else
    {
        cout<<"false";
    }
    
    return 0;
}