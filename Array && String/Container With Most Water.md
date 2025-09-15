# Problem

Find maximum amount of water a container can store.

[Container With Most Water - LeetCode](https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

2 pointer

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int res = 0;
    for(; i < j;)
    {
        int high = min(height[i], height[j]);
        int area = (j - i) * high;
        res = max(res, area);
        if(high == height[i]) i++;
        else j--;
    }
    return res;
}
```

# Notes

why not compare i++ and j-- ?

compare i and j to save max bounder.

just compare i and j is ok if compare i++ and j-- may miss the max result.

