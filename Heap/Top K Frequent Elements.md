---
id: LC347
title: Top K Frequent Elements
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

[Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/)

# Core Idea

put element into hash first 

use min-heap to store every pair && keep size smaller than k

# Invariant / Key Condition

if heap size bigger than k then pop the root(smallest one)

# Complexity

Time: O(n log k) 

Space: O(n)  n -  hash  k - heap

# Code

```c++
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> hash;
    for (int x : nums) hash[x]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for(auto & [num, cnt] : hash)
    {
        minHeap.emplace(cnt, num);
        if(minHeap.size() > k) minHeap.pop();
    }
    vector<int> res;
    while(!minHeap.empty())
    {
        res.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return res;
}
```
