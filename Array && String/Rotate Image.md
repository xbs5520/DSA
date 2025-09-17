# Problem

Rotate Image 90 degrees

[Rotate Image - LeetCode](https://leetcode.com/problems/rotate-image/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

```c++
1 2 3        1 4 7       7 4 1
4 5 6   -->  2 5 8  -->  8 5 2
7 8 9        3 6 9       9 6 3
```

# Complexity

Time: O(n^2)

Space: O(1)

# Code

```c++
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // just exchange half && not include diagonal(i != j)
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            swap(matrix[i][j], matrix[j][i]);
    // reverse every row
    for (int i = 0; i < n; ++i)
        reverse(matrix[i].begin(), matrix[i].end());
}
```
