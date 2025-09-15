# Problem

find the length of the **longest** **substring** without duplicate characters.

[Longest Substring Without Repeating Characters - LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

sliding window

using hash record every char's appear time.

if 1 char appear twice then move front point to it become once.

# Complexity

Time: O(n)

Space: O(m)

# Code

```c++
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hash;
    int res = 0;
    for(int i = 0, j = 0; j < s.size(); j++)
    {
        hash[s[j]]++;
        while(hash[s[j]] > 1) hash[s[i++]]--;
        res = max(res, j - i + 1);
    }
    return res;
}
```
