# Problem

return *all elements of the* `matrix` *in spiral order*.

[Spiral Matrix - LeetCode](https://leetcode.com/problems/spiral-matrix/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

use 4 direction array 

# Complexity

Time: O(nm)

Space: O(nm)

# Code

```c++
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<vector<int>> next = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> res(n*m);
    int i = 0, j = 0, idx = 0, dir = 0;
    while(1)
    {
        res[idx++] = matrix[i][j];
        matrix[i][j] = -1000;
        if(idx == n * m) break;
        if(i + next[dir][0] == n || i + next[dir][0] < 0 || j + next[dir][1] == m || j + next[dir][1] < 0 || matrix[i + next[dir][0]][j + next[dir][1]] == -1000)
        {
            dir++;
        }
        if(dir == 4) dir = 0;
        i = i + next[dir][0];
        j = j + next[dir][1];
    }
    return res;
}
```

# Notes

use value to control spiral, don't need change array

```c++
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> res;
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; ++j) res.push_back(matrix[top][j]);
        ++top;
        for (int i = top; i <= bottom; ++i) res.push_back(matrix[i][right]);
        --right;
        if (top <= bottom) {
            for (int j = right; j >= left; --j) res.push_back(matrix[bottom][j]);
            --bottom;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) res.push_back(matrix[i][left]);
            ++left;
        }
    }
    return res;
}
```

