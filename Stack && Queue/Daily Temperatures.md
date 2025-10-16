---
id: LC739
title: Daily Temperatures
primary_pattern: monotonic stack
secondary_patterns: []
status: DRAFT
time_min: 20
bugs: 1
looked_solution: true
revisit: 2025-10-12
---

# Problem

get next warmer index and calculate wait day

[Daily Temperatures](https://leetcode.com/problems/daily-temperatures/description/)

# Core Idea

store with monotonic stack  find next bigger one

# Invariant / Key Condition

if bigger than top then calculate wait days else push into stack

# Complexity

Time: O(n) 

Space: O(n) 

# Code

```c++
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int sz = temperatures.size();
    vector<int> res(sz, 0);
    stack<int> stk;
    for(int i = 0; i < sz; i++)
    {
        if(stk.empty() || temperatures[stk.top()] > temperatures[i]) 
        {
            stk.push(i);
            continue;
        }
        while(!stk.empty() && i < sz && temperatures[stk.top()] < temperatures[i])
        {
            cout << temperatures[stk.top()] << endl;
            int idx = stk.top(); stk.pop();
            res[idx] = i - idx;
        }
        stk.push(i);
    }
    return res;
}
```
