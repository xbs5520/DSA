# Problem

find 3 different index sum of which is equal to target

[3Sum - LeetCode](https://leetcode.com/problems/3sum/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

sort + 2 pointer

# Complexity

Time: O(n^2)

Space: O(1)

# Code

```c++
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for(int i = 0; i < n - 2; ++i)
    {
        if(i && nums[i] == nums[i - 1]) continue;
        int j = i + 1, k = n - 1;
        while(j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0)
            {
                res.push_back({nums[i], nums[j], nums[k]});
                while(j < k && nums[j] == nums[j + 1]) j++;
                while(j < k && nums[k] == nums[k - 1]) k--;
                j++, k--;
            }
            else if(sum < 0) j++;
            else k--;
        }
    }
    return res;
}
```

# Notes

if i is same as the previous one just skip that.
