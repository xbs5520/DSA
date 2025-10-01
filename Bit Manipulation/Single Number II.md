# Problem

Given an integer array `nums` where every element appears **three times** except for one, which appears **exactly once**. *Find the single element and return it*.

[Single Number II - LeetCode](https://leetcode.com/problems/single-number-ii/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

if appear 3 times == not appear at all

if just appear once then store it.

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int num : nums) {
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }
    return ones;
}
```

# Notes

[2, 2, 2]

first 2（0010）：

- ones = (0 ^ 2) & ~0 = 2 & 1111 = 2 (0010)				--> ones is result when appear just once
- twos = (0 ^ 2) & ~2 = 2 & 1101 = 0 (0000)

second 2（0010）：

- ones = (2 ^ 2) & ~0 = 0 & 1111 = 0 (0000)
- twos = (0 ^ 2) & ~0 = 2 & 1111 = 2 (0010)

third 2（0010）：

- ones = (0 ^ 2) & ~2 = 2 & 1101 = 0 (0000)
- twos = (2 ^ 2) & ~0 = 0 & 1111 = 0 (0000)

result ：ones = 0, twos = 0     --> not appear at all

