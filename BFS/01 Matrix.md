---
id: LC542
title: 01 Matrix
primary_pattern: Multi-source BFS
secondary_patterns: []
status: DRAFT
time_min: 15
bugs: 0
looked_solution: false
revisit: 2025-10-01
---

# Problem

Given an `m x n` binary matrix `mat`, return *the distance of the nearest* `0` *for each cell*.

The distance between two cells sharing a common edge is `1`.

[01 Matrix](https://leetcode.com/problems/01-matrix/description/)

# Core Idea

Push all zeros (multi-source BFS). Each popped cell relaxes 4-neighbors; first assignment of dist is shortest

# Invariant / Key Condition

if dist != -1 it has been visited (already shortest)

# Complexity

Time: O(m*n) 

Space: O(m*n) 

# Pitfall

must put all zeros into queue

All zeros => output all 0.

don't BFS every 1

# Code

```c++
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    queue<pair<int, int>> Que;
    vector<vector<int>> dist(m, vector<int>(n, -1));
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(mat[i][j] == 0)
            {
                dist[i][j] = 0;
                Que.push({i, j});
            } 
    while(Que.size())
    {
        auto p = Que.front();
        Que.pop();
        for(auto d : dir)
        {
            int Xn = p.first + d[0];
            int Yn = p.second + d[1];
            if(Xn >= 0 && Xn < m && Yn >= 0 && Yn < n)
            {
                if(dist[Xn][Yn] == -1)	// if push new node , their dist != -1
                {
                    dist[Xn][Yn] = dist[p.first][p.second] + 1;
                    Que.push({Xn, Yn});
                }
            }
        }
    }
    return dist;
}
```
