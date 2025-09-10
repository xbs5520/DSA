# Problem

give a num K rotate k steps.

12345 -> 51234 -> 45123 ...
[Rotate Array - LeetCode](https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Force: 

1.every time put last number to first  k times.

2.record the last k elements in temp-array, Move the first n - k elements to the right by k positions. then Copy the k elements from temp-array to the front.

3-times-reverse

reverse all , reverse the first k elements, reverse the next n-k elements.

# Complexity

Force1  --  Time: O(n*k) Space: O(1)

Force2  --  Time: O(n) Space: O(n)

3-times-reverse -- Time: O(n) Space: O(1)

# Code

```c++
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            std::swap(nums[start++], nums[end--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
```

# Notes

3 time reverse is for rotate Array!
