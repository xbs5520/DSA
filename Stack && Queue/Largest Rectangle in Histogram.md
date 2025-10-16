---
id: LC84
title: Largest Rectangle in Histogram
primary_pattern: Monotonic stack
secondary_patterns: []
status: DRAFT
time_min: 20
bugs: 0
looked_solution: true
revisit: 2025-10-12
---

# Problem

Given an array of integers `heights` representing the histogram's bar height 

return *the area of the largest rectangle in the histogram*.

[Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/description/)

# Core Idea

use Monotonic stack store bigger one

# Invariant / Key Condition

if next small than top , calculate area

how to calculate l is important.

push 0 to calculate last one.

# Complexity

Time: O(n) 

Space: O(n) 

# pitfall

forget last one.(push 0 to calculate last one.)

# Code

```c++
int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    stack<int> stk;
    int maxArea = 0;
    for (int i = 0; i < heights.size(); ++i) {
        while (!stk.empty() && heights[i] < heights[stk.top()]) {
            int h = heights[stk.top()]; stk.pop();
            int l = 0;  
            if(!stk.empty())
            {
                l = i - stk.top() - 1;
            } 
            else l = i;
            maxArea = max(maxArea, h * l);
        }
        stk.push(i);
    }
    return maxArea;
}
```
