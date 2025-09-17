# Problem

return `true` if `t` is an anagram of `s`, and `false` otherwise.

[Valid Anagram - LeetCode](https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

use a integer as hash to record char.

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
bool isAnagram(string s, string t) {
    int hash[30] = {0};
    if(s.size() != t.size()) return false;
    for(int i = 0; i < s.size(); i++)
    {
        int idx1 = s[i] - 'a';
        int idx2 = t[i] - 'a';
        hash[idx1]++;
        hash[idx2]--;
    }
    for(int i = 0; i < 30; i++)
    {
        if(hash[i] != 0) return false;
    }
    return true;
}
```
