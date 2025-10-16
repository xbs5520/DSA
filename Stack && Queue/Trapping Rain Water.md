---
id: LC42
title: Trapping Rain Water
primary_pattern: Monotonic stack
secondary_patterns: []
status: DRAFT
time_min: 25
bugs: 1
looked_solution: True
revisit: 2025-10-12
---

# Problem

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

# Core Idea

use monotonic stack store edge

# Invariant / Key Condition

if next element bigger than top then calculate w && h to get Area size.

# Complexity

Time: O(n) 

Space: O(n) 

# Code

```c++
int trap(vector<int>& height) {
    stack<int> stk;
    int Area = 0;
    for(int i = 0; i < height.size(); i++)
    {
        while(!stk.empty() && height[stk.top()] < height[i])
        {
            int cur = stk.top(); stk.pop();
            if(stk.empty()) break;
            int left = stk.top();
            int w = i - left - 1;
            int h = min(height[left], height[i]) - height[cur];
            Area += w * h;
        }
        stk.push(i);
    }
    return Area;
}
```
