---
id: LC752
title: Open the Lock
primary_pattern: BFS / 2 side BFS
secondary_patterns: []
status: DRAFT
time_min: 20
bugs: 1
looked_solution:true
revisit: 2025-10-02
---

# Problem

4 numbers pin each have 10 numbers from 1- 0 ;  

find out steps from 0000 -> target every time just change 1 number by 1

if during the deadends array it will locked.

# Core Idea

from 0000 - target 8 dirs for every time. BFS every one and continue when meet deadend.

# Invariant / Key Condition

get8status for string && when visited or deadend continue.

# Complexity

Time: O() 

Space: O() 

# Pitfall

first check == target then check deadends && visited -- may pass result.

# Code

```c++
auto get8status(const string& s)
{
    vector<string> res;
    res.reserve(8);
    for(int i = 0; i < 4; i++)
    {
        string t = s;
        t[i] = t[i] == '9' ? '0' : t[i] + 1;
        res.push_back(t);
        t = s;
        t[i] = t[i] == '0' ? '9' : t[i] - 1;
        res.push_back(t);
    }
    return res;
}
// 1 side
int openLock(vector<string>& deadends, string target) {
    unordered_set<string> deadMap(deadends.begin(), deadends.end());
    unordered_set<string> visited;
    if(deadMap.count("0000")) return -1;
    int step = 0;
    queue<string> que;
    que.push("0000");
    visited.insert("0000");
    while(que.size())
    {
        int sz = que.size();
        while(sz--)
        {
            string cur = que.front(); que.pop();
            if(cur == target) return step;
            for(auto &next : get8status(cur))
            {
                if(deadMap.count(next) || visited.count(next)) continue;
                visited.insert(next);
                que.push(next);
            }
        }
        step++;
    }
    return -1;
}
// 2 side
int openLock(vector<string>& deadends, string target) {
    unordered_set<string> deadMap(deadends.begin(), deadends.end());
    unordered_set<string> visited;
    if(deadMap.count("0000")) return -1;
    int step = 0;
    unordered_set<string> Front, Back;
    Front.insert("0000");
    Back.insert(target);
    visited.insert("0000");
    visited.insert(target);
    while(Front.size() && Back.size())
    {
        // always form small one.
        if(Front.size() > Back.size()) swap(Front, Back);
        unordered_set<string> next;
        for(auto &cur : Front)
        {
            if(Back.count(cur)) return step;
            if(deadMap.count(cur)) continue;
            for(auto &nxt : get8status(cur))
            {
                // check ans first!!
                if(Back.count(nxt)) return step + 1;
                if(deadMap.count(nxt) || visited.count(nxt)) continue;
                visited.insert(nxt);
                next.insert(nxt);
            }
        }
        // Front = next next = null.
        Front.swap(next);
        step++;
    }
    return -1;
}
```
