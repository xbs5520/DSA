# Problem

Each letter in `magazine` can only be used once in `ransomNote`.

[Ransom Note - LeetCode](https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Use hash record every char in magazine.

# Complexity

Time: O(n + m)

Space: O(1/k) by character map size.

# Code

```c++
bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> hash;
    for(int i = 0; i < magazine.size(); i++)
    {
        hash[magazine[i]]++;
    }
    for(int i = 0; i < ransomNote.size(); i++)
    {
        if(hash[ransomNote[i]] == 0)
            return false;
        hash[ransomNote[i]]--;
    }
    return true;
}
```
