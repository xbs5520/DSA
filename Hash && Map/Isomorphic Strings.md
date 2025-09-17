# Problem

*determine if 2 string are isomorphic*.

Isomorphic is if the characters in `s` can be replaced to get `t`.

[Isomorphic Strings - LeetCode](https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

2 way hash.

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
bool isIsomorphic(string s, string t) {
    int mapAB[300] = {0};
    int mapBA[300] = {0};
    if(s.size() != t.size()) return false;
    for(int i = 0; i < s.size(); i++)
    {
        if(mapAB[(int)s[i]] != 0 && mapAB[(int)s[i]] != (int)t[i] || mapBA[(int)t[i]] != 0 && mapBA[(int)t[i]] != (int)s[i]) return false;
        mapAB[(int)s[i]] = (int)t[i];
        mapBA[(int)t[i]] = (int)s[i];
    }
    return true;
}
```

# Notes

if more big set you can use `unordered_map<char, char>` instead.
