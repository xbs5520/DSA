# Problem

Given a **non-empty** array of integers `nums`, every element appears *twice* except for one. Find that single one.

[Single Number - LeetCode](https://leetcode.com/problems/single-number/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Use ^ operation  

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int n : nums) res ^= n;
    return res;
}
```
