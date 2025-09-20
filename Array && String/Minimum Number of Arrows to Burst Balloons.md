# Problem

Given the array `points`, return *the **minimum** number of arrows that must be shot to burst all balloons*.

[Minimum Number of Arrows to Burst Balloons - LeetCode](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

greedy,sort first. every arrow shoot most intervals.

# Complexity

Time: O(nlogn)

Space: O(1)

# Code

```c++
int findMinArrowShots(std::vector<std::vector<int>>& nums) 
{
    if (nums.empty()) return 0;
    sort(nums.begin(), nums.end(), [](const vector<int> &a , const vector<int> &b){ return a[0] < b[0];});
    int idx = nums[0][1];
    int res = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i][0] <= idx)
        {
            idx = std::min(idx, nums[i][1]);
        }
        else
        {
            res++;
            idx = nums[i][1];
        }
    }
    return res;
}
```
