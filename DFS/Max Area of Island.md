---
id: LC695
title: Max Area of Island
primary_pattern: DFS
secondary_patterns: []
status: DRATF
time_min: 10
bugs: 1
looked_solution: false
revisit: 2025-10-02
---

# Problem

Return *the maximum **area** of an island in* `grid`. If there is no island, return `0`.

area : all 1 separated by 0

# Core Idea

clear 1 from same group

# Invariant / Key Condition

if(point->val == 1) dfs that point

# Complexity

Time: O(m * n) 

Space: O(m * n) 

# Pitfall

not mark after find. --> muti-dfs

# Code

```c++
int maxAreaOfIsland(vector<vector<int>>& grid) {
    if(grid.empty() || grid[0].empty()) return 0;
    int row = grid.size(), col = grid[0].size();
    int maxarea = 0;
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    stack<pair<int, int>> stk;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(grid[i][j] == 1)
            {
                stk.push({i, j});
                // find && mark
                grid[i][j] = 0;
                int area = 0;
                while(!stk.empty())
                {
                    auto [X, Y] = stk.top(); stk.pop();
                    area++;
                    for(auto d : dirs)
                    {
                        int Xn = X + d[0];
                        int Yn = Y + d[1];
                        if(Xn >= 0 && Xn < row && Yn >= 0 && Yn < col && grid[Xn][Yn] == 1)
                        {
                            // find && mark
                            grid[Xn][Yn] = 0;
                            stk.push({Xn, Yn});
                        }
                    }
                }
                maxarea = max(area, maxarea);
            }
        }
    }
    return maxarea;
}
```
