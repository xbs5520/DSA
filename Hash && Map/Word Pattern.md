# Problem

find if `s` follows the same pattern.

[Word Pattern - LeetCode](https://leetcode.com/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

2 way hash

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
bool wordPattern(string pattern, string s) {
    unordered_map<char, string> mapAB;
    unordered_map<string, char> mapBA;
    int i = 0, j = 0;
    for(; i < pattern.size() && j < s.size(); i++, j++)
    {
        string cur;
        while(j < s.size() && s[j] != ' ') cur += s[j++];
        if(mapAB.count(pattern[i]) && mapAB[pattern[i]] != cur || mapBA.count(cur) && mapBA[cur] != pattern[i]) return false;
        mapAB[pattern[i]] = cur;
        mapBA[cur] = pattern[i];
    }
    return i >= pattern.size() && j >= s.size();
}
```

# Notes

use `istringstream` to  get single word.

```c++
    istringstream iss(s);
    vector<string> words;
    string word;
    while (iss >> word) words.push_back(word);
```

