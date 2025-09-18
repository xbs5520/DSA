# Problem

1. Any live cell with fewer than two live neighbors dies as if caused by under-population.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by over-population.
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

[Game of Life - LeetCode](https://leetcode.com/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Force:  count every live cell number use a copy board to store.

Optimized:  use original board to store. 

# Complexity

Force Time: O(m * n) Space: O(m * m)

Optimized Time: O(m * n) Space: O(1)

# Code

```c++
    int Mycount(int i, int j, vector<vector<int>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        int res = 0;
        if(i - 1 >= 0 && j - 1 >= 0)
            res += (board[i - 1][j - 1] % 2);
        if(i - 1 >= 0)
            res += (board[i - 1][j] % 2);
        if(j - 1 >= 0)
            res += (board[i][j - 1] % 2);
        if(i - 1 >= 0 && j + 1 < m)
            res += (board[i - 1][j + 1] % 2);
        if(j - 1 >= 0 && i + 1 < n)
            res += (board[i + 1][j - 1] % 2);
        if(j + 1 < m)
            res += (board[i][j + 1] % 2);
        if(i + 1 < n)
            res += (board[i + 1][j] % 2);
        if(i + 1 < n && j + 1 < m)
            res += (board[i + 1][j + 1] % 2);
        return res;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                int count = Mycount(i, j, board);
                // need to change to 0 save as 3 because it was 1  
                if(board[i][j] % 2 && (count < 2 || count > 3)) board[i][j] = 3;
                // need to change to 1 save as 2 because it was 0
                if(!(board[i][j] % 2) && count == 3) board[i][j] = 2;
            }
        }
        // change to 0  1
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == 3) board[i][j] = 0;
                if(board[i][j] == 2) board[i][j] = 1;
            }
    }
```
