---
id: LC215
title: Kth Largest Element in an Array
primary_pattern: Min heap
secondary_patterns: []
status: DRAFT
time_min: 15
bugs: 0
looked_solution: true
revisit: 2025-10-15

---

# Problem

Given an integer array `nums` and an integer `k`, return *the* `k` *most frequent elements*. You may return the answer in **any order**.

[Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)

# Core Idea

use min-heap to store every element && keep size smaller than k

# Invariant / Key Condition

if heap size bigger than k then pop the root(smallest one)

# Complexity

Time: O(n log k) 

Space: O(k) 

# Code

```c++
int findKthLargest(vector<int>& nums, int k) {
    for (int x : nums) {
        heapinsert(x);
        if (g_Size > k) heappop();
    }
    return heaptop();
}
```
