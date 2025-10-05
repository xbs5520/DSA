---
id: LC200
title: Number of Islands
primary_pattern: DFS
secondary_patterns: []
status: DRAFT
time_min: 10
bugs: 1
looked_solution: false
revisit: 2025-10-02
---

# Problem

*the number of islands*. group 1 sperated by zero

# Core Idea

dfs clear all 1 to 0 for a group

# Invariant / Key Condition

find value == 1 and do dfs for that pointer

# Complexity

Time: O(m * n) 

Space: O(m * n) 

# Pitfall

forget to set status(0)  when find '1'

no boundary check

# Code

```c++
int numIslands(vector<vector<char>>& grid) {
    if(grid.empty() || grid[0].empty()) return 0;
    int n, m;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    n = grid.size();
    m = grid[0].size();
    int count = 0;
    stack<pair<int, int>> stk;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == '1')
            {
                count++;
                grid[i][j] = '0';                    stk.push({i, j});
                while(!stk.empty())
                {
                    auto p = stk.top(); stk.pop();
                    for(auto d : dir)
                    {
                        int Xn = p.first + d[0];
                        int Yn = p.second + d[1];
                        if(Xn >= 0 && Xn < n && Yn >=0 && Yn < m && grid[Xn][Yn] == '1')
                        {
                            grid[Xn][Xn] = '0';
                            stk.push({Xn, Yn});
                        }
                    }
                }
            }
        }
    }
    return count;
}
```
