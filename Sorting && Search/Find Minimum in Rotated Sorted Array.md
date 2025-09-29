# Problem

Suppose an array of length `n` sorted in ascending order is **rotated** between `1` and `n` times.

Given the sorted rotated array `nums` of **unique** elements, return *the minimum element of this array*.

[Find Minimum in Rotated Sorted Array - LeetCode](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Binary Search find the one bigger than left

# Complexity

Time: O(logn)

Space: O(1)

# Code

```c++
int findMin(vector<int>& nums) {
    int i = 0, j = nums.size() - 1;
    while(i <= j)
    {
        int mid = i + (j - i) / 2;
        if(mid - 1 >= 0 && nums[mid] < nums[mid - 1]) return nums[mid];
        else if(nums[mid] > nums[j]) i = mid + 1;
        else j = mid - 1; 	// if not rotate go left where min is.
    }
    return nums[i];
}
```
