# Problem

return *the **minimal length** of a* *subarray* *whose sum is **greater than or equal** to* `target`

[Minimum Size Subarray Sum - LeetCode](https://leetcode.com/problems/minimum-size-subarray-sum/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Slide window

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
int minSubArrayLen(int target, vector<int>& nums) {
    int res = INT_MAX;
    if(!nums.size()) return 0;
    int cur = nums[0];
    for(int i = 0, j = 0; i <= j && j < nums.size();)
    {
        cout << i << " " << j << "\n";
        if(cur >= target)
        {
            res = min(res, j - i + 1);
            cur -= nums[i];
            i++;
        }
        else if(cur < target)
        {
            j++;
            if(j < nums.size())
            {
                cur += nums[j];
            }
        }
    }
    return res == INT_MAX ? 0 : res;
    }
```

# Notes

Problems is greater than or equal!
