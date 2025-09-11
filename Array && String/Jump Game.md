# Problem

Find if you can jump to last from first one

[Jump Game - LeetCode](https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Reverse Greedy: update start point furthest you can reach .

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
    bool canJump(vector<int>& nums) {
        int idx = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(i + nums[i] >= idx) idx = i;
        }
        return idx == 0;
    }
```
