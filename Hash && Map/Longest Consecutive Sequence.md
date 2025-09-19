# Problem

return *the length of the longest consecutive elements sequence*

[Longest Consecutive Sequence - LeetCode](https://leetcode.com/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-interview-150)

# Approach

push all numbers into hash.

Find the first of consecutive elements and begin to find next one.

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> hash;
    for(int i = 0; i < nums.size(); i++)
    {
        hash.insert(nums[i]);
    }
    int res = 0;
    for(auto &n : hash)
    {
        if(hash.find(n - 1) == hash.end())
        {
            int x = n;
            while(hash.find(x + 1) != hash.end()) x += 1;
            res = max(res, x - n + 1);
        }
    }
    return res;
}
```
