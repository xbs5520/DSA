---
id: LC713
title: Subarray Product Less Than K
primary_pattern: sliding window
secondary_patterns: []
status: DRAFT
time_min: 10
bugs: 1
looked_solution: true
revisit: 2025-10-07
---

# Problem

Given an array of integers `nums` and an integer `k`, return *the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than* `k`.

# Core Idea

sliding window

# Invariant / Key Condition

if a window which numbers' product less than k then  -- > res += j - i + 1

# Complexity

Time: O(n) 

Space: O(1) 

# Pitfall

not use sliding window use n^2 visited.

# Code

```c++
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    int res = 0;
    int prod = 1;
    int i = 0;
    for(int j = 0; j < nums.size(); j++)
    {
        prod *= nums[j];
        while(prod >= k) prod /= nums[i++];
        res += j - i + 1;
    }
    return res;
}
```
