# Problem

A peak element is an element that is strictly greater than its neighbors. find a peak element, and return its index. 

[Find Peak Element - LeetCode](https://leetcode.com/problems/find-peak-element/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Binary search: compare nums[mid] with nums[mid + 1]

# Complexity

Time: O(logn)

Space: O(1)

# Code

```c++
int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] < nums[mid + 1])
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
```
