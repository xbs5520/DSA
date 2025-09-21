# Problem

You are given an array of strings `tokens` that represents an arithmetic expression in a [Reverse Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Evaluate the expression. Return *an integer that represents the value of the expression*.

[Evaluate Reverse Polish Notation - LeetCode](https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

use a stack to store all numbers. use top 2 numbers to calculate with next operator, and push result into stack.

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for(auto str : tokens)
    {
        if(str == "+" || str == "-" || str == "*" || str == "/")
        {
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            if(str == "+") stk.push(a + b);
            if(str == "-") stk.push(a - b);
            if(str == "*") stk.push(a * b);
            if(str == "/") stk.push(a / b);
        }
        else
        {
            stk.push(stoi(str));
        }
    }
    return stk.top();
}
```

# Notes

the sequence of a and b is important.
