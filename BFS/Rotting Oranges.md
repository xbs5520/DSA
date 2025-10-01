---
id: LC994
title: Rotting Oranges
primary_pattern: Multi-source BFS
secondary_patterns: []
status: DRAFT
time_min: 20
bugs: 1
looked_solution: false
revisit: 2025-10-01
---

# Problem

Given an m×n grid: 0=empty, 1=fresh orange, 2=rotten orange. 

Each minute every rotten spreads to its 4-direction fresh neighbors. 

Return the minimum minutes until all fresh become rotten, or -1 if impossible.

[Rotting Oranges](https://leetcode.com/problems/rotting-oranges/description/)

# Core Idea

Push all initial rotten cells into a queue (multi-source BFS). 

Each BFS layer = 1 minute of simultaneous spread.

# Invariant / Key Condition

The first time we convert a fresh cell, the current layer index is its minimal rot time.

# Complexity

Time: O(m * n)  (each cell enqueued at most once)  

Space: O(m * n) queue worst-case

# Pitfall

Forget to count initial fresh

fresh==0 → return 0

no rotten but fresh>0 → return -1

BFS done and fresh>0 → return -1 

# Code

```c++
int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int,int>> q;
    int fresh = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j] == 2) q.emplace(i,j);
    		else if (grid[i][j] == 1) fresh++;

    if (fresh == 0) return 0;
    if (q.empty()) return -1;

    int minutes = -1;
    const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while (!q.empty()) {
        int sz = q.size();
        minutes++;
        while (sz--) {
            auto [x,y] = q.front(); q.pop();
            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (grid[nx][ny] != 1) continue;
                grid[nx][ny] = 2;
                fresh--;
                q.emplace(nx, ny);
            }
        }
    }
    return fresh == 0 ? minutes : -1;
}
```
