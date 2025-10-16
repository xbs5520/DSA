---
id: LC496
title: Next Greater Element I
primary_pattern: Monotonic stack && hash
secondary_patterns: []
status: DRAFT
time_min: 15
bugs: 1
looked_solution: false
revisit: 2025-10-12
---

# Problem

return next bigger element

[Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)

# Core Idea

store smaller with Monotonic stack  

# Invariant / Key Condition

if next bigger than top then top element‘ s bigger one is this one.

# Complexity

Time: O(n + m) 

Space: O(n) 

# Pitfall

push wrong element(index) into stack

# Code

```c++
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> hash;
    stack<int> stk;
    for(int i = 0; i < nums2.size(); i++)
    {
        if(stk.empty() || stk.top() > nums2[i])
        {
            stk.push(nums2[i]);
            continue;
        }
        while(!stk.empty() && i < nums2.size() && stk.top() < nums2[i])
        {
            int cur = stk.top(); stk.pop();
            hash[cur] = nums2[i];
        }
        stk.push(nums2[i]);
    }
    vector<int> res(nums1.size(), -1);
    for(int i = 0; i < nums1.size(); i++)
    {
        if(hash.find(nums1[i]) != hash.end())
        {
            res[i] = hash[nums1[i]];
        }
    }
    return res;
}
```
