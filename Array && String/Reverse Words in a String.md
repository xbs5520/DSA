# Problem

Given an input string `s`, reverse the order of the **words**.

[Reverse Words in a String - LeetCode](https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Force:  find every word then push them into result -- to many times using string + ...

Optimized:  Using vector<string> record words -- just once Append each word to the result string

# Complexity

Same Time: O(n) Space: O(n)

# Code

```c++
string reverseWords(string s) {
    string tmp = "";
    string res = "";
    for(int i = s.size() - 1; i >= 0; i--)
    {
        tmp = "";
        if(s[i] != ' ')
        {
            while(i >= 0 && s[i] != ' ') tmp = s[i--] + tmp;
            res += tmp + " ";
        }
    }
    if(res.back() == ' ') res.pop_back();
    return res;
}
// Optimized
string reverseWords(string s) {
    vector<string> words;
    int i = 0, n = s.size();
    while (i < n) {
        while (i < n && s[i] == ' ') ++i; // 跳过空格
        int j = i;
        while (j < n && s[j] != ' ') ++j; // 找到单词
        if (i < j) words.push_back(s.substr(i, j - i));
        i = j;
    }
    reverse(words.begin(), words.end());
    string res;
    for (int k = 0; k < words.size(); ++k) {
        if (k > 0) res += " ";
        res += words[k];
    }
    return res;
}
```

# Notes

When using string += to many times it may be slow.
