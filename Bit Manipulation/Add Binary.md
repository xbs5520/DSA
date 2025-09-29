# Problem

Given two binary strings `a` and `b`, return *their sum as a binary string*.

[Add Binary - LeetCode](https://leetcode.com/problems/add-binary/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

first add 0 to front of short string.

simulate to sum numbers from back to start of string.

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
string addBinary(string a, string b) {
    if(a.size() > b.size())
        while(a.size() > b.size()) b = '0' + b;
    if(a.size() < b.size())
        while(a.size() < b.size()) a = '0' + a;
    int n = a.size();
    string res(n, '0');
    bool flag = false;
    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] == b[i] && a[i] == '1')
        {
            if(flag) res[i] = '1';
            else  res[i] = '0';
            flag = true;
        }
        else if(a[i] == b[i] && a[i] == '0')
        {
            if(flag) res[i] = '1';
            else res[i] = '0';
            flag = false;
        }
        else
        {
            if(flag)
            {
                res[i] = '0';
                flag = true;
            }
            else res[i] = '1';
        }
    }
    if(flag) res = '1' + res;
    return res;
}
```

# Notes

when use string it is quicker to initialize string with its length first then fill it.
