# Problem

put Anagrams into vector.

[Group Anagrams - LeetCode](https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Force:  every time check if strs[i] is Anagram to other vector's first word. if not add a group.

Optimized:  every time sort strs[i] use a hash to store. At the end put them together.

# Complexity

Force:  Time: O(n^2*k) Space: O(n * k)

optimized: Time: O(n*k * logn) Space: O(n * k)

# Code

```c++
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (const auto& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    vector<vector<string>> res;
    for (auto& p : groups) res.push_back(move(p.second));
    return res;
}
```
