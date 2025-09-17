# Problem

if an element is `0`, set its entire row and column to `0`'s.

[Set Matrix Zeroes - LeetCode](https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

force: use 2 hash record row && col is 0 or not

optimize: use first one in col and row to record

# Complexity

force -- Time: O(m * n) Space: O(m + n)

optimize --  Time: O(m * n) Space: O(1)

# Code

```c++
// force
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0u].size();
    std::vector<bool> row(m);
    std::vector<bool> col(n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (0 == matrix[i][j])
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}
// optimize
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRowZero = false, firstColZero = false;

    // mark first col and row
    for (int i = 0; i < m; ++i)
        if (matrix[i][0] == 0) firstColZero = true;
    for (int j = 0; j < n; ++j)
        if (matrix[0][j] == 0) firstRowZero = true;

    // use first one to record
    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;

    // set 0
    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

    // deal with first col and row
    if (firstColZero)
        for (int i = 0; i < m; ++i)
            matrix[i][0] = 0;
    if (firstRowZero)
        for (int j = 0; j < n; ++j)
            matrix[0][j] = 0;
}
```
