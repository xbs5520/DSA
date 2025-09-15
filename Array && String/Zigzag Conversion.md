# Problem

Output String on zigzag pattern

[Zigzag Conversion - LeetCode](https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

simulate zigzag

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s;
        vector<string> strs(numRows);
        int idx = 0, step = 1;
        for(char c : s)
        {
            strs[idx] += c;
            // simulate zigzag
            if(idx == 0) step = 1;
            if(idx == numRows - 1) step = -1;
            idx += step; 
        }
        string res;
        for(string str : strs)
        {
            res += str;
        }
        return res;
    }
```
