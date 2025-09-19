# Problem

Given a **sorted unique** integer array `nums`.

Return *the **smallest sorted** list of ranges that **cover all the numbers in the array exactly***.

[Summary Ranges - LeetCode](https://leetcode.com/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

find first non-consecutive number as start point, then find end of it. then put them in result.

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    string str = "";
    for(int i = 0; i < nums.size(); i++)
    {
        if(str == "") str += to_string(nums[i]);
        int j = i;
        while(j + 1 < nums.size() && (nums[j + 1] == (nums[j] + 1))) j++;
        if(i != j) str += "->" + to_string(nums[j]), i = j;
        res.push_back(str);
        str = "";
    }
    return res;
}
```
