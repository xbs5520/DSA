# Problem

Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all overlapping intervals

[Merge Intervals - LeetCode](https://leetcode.com/problems/merge-intervals/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Sort the array by the first element of each subarray.

merge all array.

# Complexity

Time: O(nlogn)

Space: O(n)

# Code

```c++
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    vector<int> cur;
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { 
        return a[0] < b[0];});
    int right;
    for(int i = 0; i < intervals.size(); i++)
    {
        if(cur.empty())
        {
            cur.push_back(intervals[i][0]);
            right = intervals[i][1];
        } 
        while(i < intervals.size() - 1 && intervals[i + 1][0] <= right)
        {
            cout << i << "\n";
            right = max(right, intervals[i + 1][1]);
            i++;
        } 
        right = max(right, intervals[i][1]);
        cur.push_back(right);
        res.push_back(cur);
        cur = {};
    } 
    return res;
}
```

# Notes

How to sort array by first element of subarray.

```c++
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { 
        return a[0] < b[0];});
```

