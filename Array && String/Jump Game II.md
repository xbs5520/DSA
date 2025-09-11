# Problem

Find min-stop you go to last point.

[Jump Game II - LeetCode](https://leetcode.com/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Greedy: update furthest point you can reach when go to it jump++.

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump = 0, end = 0, far = 0;
        for(int i = 0; i < n - 1; i++)
        {
            far = max(far, i + nums[i]);
            if(i == end)
            {
                jump++;
                end = far;
            }
        }
        return jump;
    }
```

