# Problem

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

[Min Stack - LeetCode](https://leetcode.com/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

use 2 stack to store element 1 is normal stack 1 is saving min-numbers.

# Complexity

Time: O(1)

Space: O(n)

# Code

```c++
class MinStack {
public:
    MinStack() {}
    void push(int val) {
        stk.push(val);
        if(minstk.empty() || minstk.top() >= val)
        {
            minstk.push(val);
        }
    }
    void pop() {
        if(stk.top() == minstk.top())
        {
            minstk.pop();
        }
        stk.pop();
    }
    int top() {
        return stk.top();
    }
    int getMin() {
        return minstk.top();
    }
private:
    stack<int> stk;
    stack<int> minstk;
};
```

# Notes

`minstk.top() >= val`

when top is equal to val then val need to be push into min-stack.
