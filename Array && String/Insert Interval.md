# Problem

Add a new interval to intervals and merge them.

[Insert Interval - LeetCode](https://leetcode.com/problems/insert-interval/?envType=study-plan-v2&envId=top-interview-150)

# Approach

find right and left of merged interval.

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
vector<vector<int>> insert(vector<vector<int>>& it, vector<int>& newit) {
    vector<vector<int>> res;
    if(it.size() == 0) 
    {
        res.push_back(newit);
        return res;
    }
    int flag = 0;
    for(int i = 0; i < it.size(); i++)
    {
        if(it[i][1] < newit[0] || flag)
        {
            res.push_back(it[i]);
        }
        else
        {
            int left = min(it[i][0], newit[0]);
            int right = newit[1];
            while(i < it.size() && it[i][1] < right)  i++;
            if(i < it.size() && right >= it[i][0]) right = it[i][1];
            else i--;
            res.push_back({left, right});
            flag = 1;
        }
    }
    if(!flag) res.push_back(newit);
    return res;
}
```
