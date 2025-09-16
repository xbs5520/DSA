# Problem

check if sudoku board is valid

[Valid Sudoku - LeetCode](https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

use 3 bool hash board to check row && col && block is valid

# Complexity

Time: O(1)

Space: O(1)

# Code

```c++
bool isValidSudoku(vector<vector<char>>& board) {
    bool row[9][9] = {0};
    bool col[9][9] = {0};
    bool rect[9][9] = {0};
    for(int i = 0, j = 0; i < 9 && j < 9; i++)
    {
        char x = board[i][j];
        if(isdigit(x))
        {
            int n = x - '0';
            n -= 1;
            if(row[i][n] || col[j][n] || rect[(i / 3) * 3+ j / 3][n]) return false;
            row[i][n] = 1;
            col[j][n] = 1;
            rect[(i / 3) * 3+ j / 3][n] = 1;
        }
        if(i == 8) i = -1, j++;
    }
    return true;
}
```

# Notes

when i = 8 then i go to -1 because i will add 1 in next circle.

**(i / 3) * 3+ j / 3 **    is    **9 * 9 -> 3 * 3**
