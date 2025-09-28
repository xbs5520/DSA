# Problem

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

[Search Insert Position - LeetCode](https://leetcode.com/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Binary Search

# Complexity

Time: O(logn)

Space: O(logn)

# Code

```c++
int search(vector<int>& nums, int target, int l, int r)
{
    if(l > r) return l;
    int mid = l + (r - l) / 2;
    if(nums[mid] == target) return mid;
    if(target < nums[mid]) return search(nums, target, l, mid - 1);
    else return search(nums, target, mid + 1, r);
}
int searchInsert(vector<int>& nums, int target) {
    return search(nums, target, 0, nums.size() - 1);
}
```

# Notes

`mid = l + (r - l) / 2`

in case  l + R > INT_MAX
