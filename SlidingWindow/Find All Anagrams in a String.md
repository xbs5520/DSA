---
id: LC438
title: Find All Anagrams in a String
primary_pattern: hash + sliding window
secondary_patterns: []
status: DRAFT
time_min: 8
bugs: 0
looked_solution:0
revisit: 2025-10-07
---

# Problem

Given two strings `s` and `p`, return an array of all the start indices of `p`'s anagrams in `s`. You may return the answer in **any order**.

# Core Idea

hash + sliding window

# Invariant / Key Condition

when window slides pop first one and push new && update the hash map

# Complexity

Time: O(n) 

Space: O(1) 

# Pitfall

Forget the window size must equal to s1.size()

# Code

```c++
vector<int> findAnagrams(string s, string p) {
    if(p.size() > s.size()) return {};
    vector<int> res;
    vector<int> pmap(26, 0), smap(26, 0);
    for(auto &c : p) pmap[c - 'a']++;
    for(int i = 0; i < p.size(); i++)
    {
        smap[s[i] - 'a']++;
    }
    if(smap == pmap) res.push_back(0);
    for(int i = p.size(); i < s.size(); i++)
    {
        smap[s[i] - 'a']++;
        smap[s[i - p.size()] - 'a']--;
        if(smap == pmap) res.push_back(i - p.size() + 1);
    }
    return res;
}
```
