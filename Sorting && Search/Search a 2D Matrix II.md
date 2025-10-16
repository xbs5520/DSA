---
id: LC240
title: Search a 2D Matrix II
primary_pattern: Z search
secondary_patterns: []
status: DRAFT
time_min: 6
bugs: 0
looked_solution: true
revisit: 2025-10-09
---

# Problem

find x in array return true or false

- Integers in each row are sorted in ascending from left to right.
- Integers in each column are sorted in ascending from top to bottom.

# Core Idea

start from (n  - 1, 0) or (0, m - 1) ->> every time cut 1 col/row.

# Invariant / Key Condition

 z search must 1 increase 1 decrease！

# Complexity

Time: O(m + n) 

Space: O(1) 

# Pitfall

not begin from  (n  - 1, 0) or (0, m - 1) 

# Code

```c++
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i = matrix.size() - 1;
    int j = 0;
    for(; i >= 0 && j < matrix[0].size();)
    {
        if(matrix[i][j] == target) return true;
        else if(matrix[i][j] > target) i--;
        else j++;
    }
    return false;
}
```
