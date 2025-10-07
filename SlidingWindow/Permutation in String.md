---
id: LC567
title: Permutation in String
primary_pattern: Hash， sliding window
secondary_patterns: []
status: DRAFT
time_min: 10
bugs: 0
looked_solution: true
revisit: 2025-10-07
---

# Problem

Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`, or `false` otherwise.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.

# Core Idea

sliding window + hash 

# Invariant / Key Condition

when window slides pop first one and push new && update the hash map

# Complexity

Time: O(n) 

Space: O(1) 

# Pitfall

Forget the window size must equal to s1.size()

if s1 longer than s2 then return

# Code

```c++
bool checkInclusion(string s1, string s2) {
    if(s1.size() > s2.size()) return false;
    vector<int> s1map(26, 0), s2map(26, 0);
    for(auto &c : s1)
    {
        s1map[c - 'a']++;
    }
    for(int i = 0; i < s1.size(); i++)
    {
        s2map[s2[i] - 'a']++;
    }
    if(s1map == s2map) return true;
    for(int i = s1.size(); i < s2.size(); i++)
    {
        s2map[s2[i] - 'a']++;
        s2map[s2[i - s1.size()] - 'a']--;
        if(s1map == s2map) return true;
    }
    return false;
}
```
