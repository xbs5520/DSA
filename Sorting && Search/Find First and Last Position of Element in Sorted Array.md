# Problem

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

[Find First and Last Position of Element in Sorted Array - LeetCode](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Binary Search 2 times, 1 for left, 1 for right (if find same number find in one side)

# Complexity

Time: O(logn)

Space: O(1)

# Code

```c++
vector<int> searchRange(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    int res = -1;
    while(i <= j)
    {
        int mid = i + (j - i) / 2;
        if(nums[mid] == target) 
        {
            res = mid;
            if(mid - 1 < 0 || nums[mid - 1] != target) break;
            j = mid - 1;
        }
        else if(nums[mid] > target) j = mid - 1;
        else i = mid + 1;
    }
    int left = res;

    res = -1;
    i = 0;
    j = nums.size() - 1;
    while(i <= j)
    {
        int mid = i + (j - i) / 2;
        if(nums[mid] == target) 
        {
            res = mid;
            if(mid + 1 >= nums.size() || nums[mid + 1] != target) break;
            i = mid + 1;
        }
        else if(nums[mid] > target) j = mid - 1;
        else i = mid + 1;
    }
    int right = res;
    return {left, right};
}
```
