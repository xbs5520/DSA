# Problem

check if it is subsequence

[Is Subsequence - LeetCode](https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

2 pointer

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
bool isSubsequence(string s, string t) {
    int i = 0, j = 0; 
    for(; i < s.size() && j < t.size(); j++)
    {
        if(s[i] == t[j]) i++;
    }
    return i == s.size();
}
```
