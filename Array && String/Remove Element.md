# Problem

remove all numbers which are equal to val

[Remove Element - LeetCode](https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

2pointer fast and slower

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
int removeElement(vector<int>& nums, int val) {
    int cur = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != val)
        {
            nums[cur++] = nums[i];
        } 
    }
    return cur;
}
```

# Notes

boundary handling

