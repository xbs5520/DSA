# Problem

You are given an `m x n` integer matrix `matrix` with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.
- [Search a 2D Matrix - LeetCode](https://leetcode.com/problems/search-a-2d-matrix/?envType=study-plan-v2&envId=top-interview-150)

# Approach

2 times binary search

# Complexity

Time: O(log(m*n))

Space: O(log(m*n))

# Code

```c++
bool searchinL(vector<int>& line, int target, int l, int r)
{
    if(l > r) return false;
    int mid = l + (r - l) / 2;
    if(line[mid] < target) return searchinL(line, target, mid + 1, r);
    else if(line[mid] > target) return searchinL(line, target, l, mid - 1);
    else return true;
}

bool searchL(vector<vector<int>>& matrix, int target, int l, int r)
{
    if(l > r) return false;
    int mid = l + (r - l) / 2;
    int j = matrix[0].size() - 1;
    if(matrix[mid][j] >= target && matrix[mid][0] <= target) 
    {
        vector<int> line = matrix[mid];
        return searchinL(line, target, 0, line.size() - 1);
    }
    else if(matrix[mid][0] > target)  return searchL(matrix, target, l, mid - 1);
    else return searchL(matrix, target, mid + 1, r);
    return true;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size()) return false;
    return searchL(matrix, target, 0, matrix.size() - 1);
}
```
