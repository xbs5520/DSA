# Problem

Find the majority number in Array.

[Majority Element - LeetCode](https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Force: sort && find the middle one

Optimized: **Vote Algorithm**

# Complexity

Force -- Time: O(nlogn) Space: O(1)

Vote -- Time: O(n) Space: O(1)

# Code

```c++
    int majorityElement(vector<int>& nums) {
        int maj = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(cnt == 0) maj = nums[i], cnt = 1;
            else
            {
                if(maj == nums[i]) cnt++;
                else cnt--;
            }
        }
        return maj;
    }
```
