# Problem

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

[Valid Parentheses - LeetCode](https://leetcode.com/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

use stack store char if next is a pair of top then pop it.

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
bool isValid(string s) {
    stack<char> stk;
    for(auto c : s)
    {
        if(c == '(' || c == '[' || c == '{')
            stk.push(c);
        else if(!stk.empty() && (c == ')' && stk.top() == '(' || c == ']' && stk.top() == '[' || c == '}' && stk.top() == '{'))
            stk.pop();
        else
            return false;
    }
    return stk.empty();
}
```
