# Problem

if *n the array such that* `nums[i] == nums[j]` *and* `abs(i - j) <= k`.  return true

[Contains Duplicate II - LeetCode](https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

use hash to store the nearest number's index. check every time with same number.

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> hash;
    for(int i = 0; i < nums.size(); i++)
    {
        if(hash.find(nums[i]) != hash.end())
        {
            if(k >= (i - hash[nums[i]])) return true;
        }
        hash[nums[i]] = i;
    }
    return false;
}
```

# Notes

hash must update every time to store the nearest index. 
