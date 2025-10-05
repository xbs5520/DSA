---
id: LC
title: 
primary_pattern:
secondary_patterns: []
status: 
time_min: 
bugs: 
looked_solution:
revisit: 2025-10-01
---

# Problem

give a start point flood fill with given color for group of that point

group : points with same color.

# Core Idea

use dfs make all original color become given color

# Invariant / Key Condition

dfs 4 dirs of stk top pointer.

# Complexity

Time: O(m * n) 

Space: O(m * n) 

# Pitfall

if same color do not need to fill

not set color of this group and compare with 0

# Code

```c++
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
{
    if(image.empty() || image[0].empty()) return image;
    int row = image.size(), col = image[0].size();
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    stack<pair<int, int>> stk;
    int originalColor = image[sr][sc];
    if(originalColor == color) return image;
    image[sr][sc] = color;
    stk.push({sr, sc});

    while(stk.size())
    {
        auto [X, Y] = stk.top(); stk.pop();
        for(auto d : dirs)
        {
            int Xn = X + d[0];
            int Yn = Y + d[1];
            if(Xn >= 0 && Xn < row && Yn >= 0 && Yn < col && image[Xn][Yn] == originalColor)
            {
                image[Xn][Yn] = color;
                stk.push({Xn, Yn});
            }
        }
    }
    return image;
}
```
