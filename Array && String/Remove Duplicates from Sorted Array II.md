# Problem

Remove duplicates in-place && element can appears at most twice.

[Remove Duplicates from Sorted Array II - LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Force: use a new array storage and count numbers.

Optimized: 2pointer with flag.

# Complexity

Force -- Time: O(n)Space: O(n)

2pointer -- Time: O(n)Space: O(1)

# Code

```c++
int removeDuplicates(vector<int>& nums) {
    int i = 0, j = 1;
    bool flag = false;
    for(; j < nums.size(); j++)
    {
        if(nums[j - 1] != nums[j])
        {
            i++;
            nums[i] = nums[j];
            flag = false;
        }
        else
        {
            if(!flag)
            {
                i++;
                nums[i] = nums[j];
                flag = true;
            }
        }
    }
    return i + 1;
}
```

# Notes

same way but easy to write.

```c++
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums) {
        if (i < 2 || n != nums[i - 2]) {
            nums[i++] = n;
        }
    }
    return i;
}
```

