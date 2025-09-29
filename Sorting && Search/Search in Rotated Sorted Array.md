# Problem

There is an integer array `nums` sorted in ascending order (with **distinct** values).

return *the index of* `target` *if it is in* `nums`*, or* `-1` *if it is not in* `nums`.

[Search in Rotated Sorted Array - LeetCode](https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Binary Search && discuss different cases

# Complexity

Time: O(logn)

Space: O(1)

# Code

```c++
int search(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    while(j >= i)
    {
        int mid = i + (j - i) / 2;
        if(nums[i] == target) return i;
        if(nums[j] == target) return j;
        if(nums[mid] == target) return mid;
        if(nums[i] > nums[j])
        {
            if(nums[mid] > nums[i])
            {
                if(target > nums[i] && target < nums[mid]) j = mid - 1;
                else i = mid + 1;
            }
            else
            {
                if(target > nums[mid] && target < nums[j]) i = mid + 1;
                else j = mid - 1;
            }
        } 
        else
        {
            if(target > nums[mid]) i = mid + 1;
            else j = mid - 1;
        }
    }
    return -1;
}
```
