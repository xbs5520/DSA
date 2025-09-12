# Problem

find the longest common prefix string amongst a string array

[Longest Common Prefix - LeetCode](https://leetcode.com/problems/longest-common-prefix/?envType=study-plan-v2&envId=top-interview-150)

# Approach

visit the first string's every char if any string's same index char doesn't same with char return result else result += char.

# Complexity

Time: O(n m)

Space: O(1)

# Code

```c++
string longestCommonPrefix(vector<string>& strs) {
    string res = "";
    for(int i = 0; i < strs[0].size(); i++)
    {
        char c = strs[0][i];
        for(int j = 1; j < strs.size(); j++)
        {
            if(c != strs[j][i]) return res;
        }
        res += c;
    }
    return res;
}
```
