# Problem

Array is non-decreasing order, remove the duplicates in-place.

[Remove Duplicates from Sorted Array - LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Force: New Array compare with last new one  

Optimized: 2 pointer

# Complexity

Force  -- Time: O(n) Space: O(n)

2pointer -- Time: O(n) Space: O(1)

# Code

```c++
int removeDuplicates(vector<int>& nums) {
    int i = 0, j = 1;
    for(; j < nums.size(); j++)
    {
        if(nums[j - 1] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
```
