# Problem

Out put a array every element is product of given Array except itself(index). 

limit: Time O(n)

[Product of Array Except Self - LeetCode](https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Force:  Calculate a left array which is every element's product of their left. And a right array. 

Optimized: Don't need array to restore just restore in result.

# Complexity

Force -- Time: O(n) Space: O(n)

Optimized -- Time: O(n) Space: O(1)

# Code

```c++
// force
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n, 1);
    vector<int> right(n, 1);

    for(int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }
    for(int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }

    vector<int> res(n, 0);
    for(int i = 0; i < n; i++)
    {
        res[i] = left[i] * right[i];
    }
    return res;
}
// optimized
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 1);
    //left
    for (int i = 1; i < n; ++i) {
        res[i] = res[i - 1] * nums[i - 1];
    }
    // the last already changed. so cant use last one
    int right = 1;
    for (int i = n - 1; i >= 0; --i) {
        res[i] *= right;
        right *= nums[i];
    }
    return res;
}
```

# Notes

Product of Array meaning 

A * B * C ...
