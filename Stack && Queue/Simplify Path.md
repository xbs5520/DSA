# Problem

You are given an *absolute* path for a Unix-style file system, which always begins with a slash `'/'`. Your task is to transform this absolute path into its **simplified canonical path**.

[Simplify Path - LeetCode](https://leetcode.com/problems/simplify-path/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

exchange '/' to ' ' first.

use stack to store each word. dealing with special ".." and "." others is word for this problem.

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
string simplifyPath(string path) {
    stack<string> stk;
    for(auto &c : path) if(c == '/') c = ' ';
    istringstream iss(path);
    string word;
    while (iss >> word)
    {
        if(word == "..")
        {
            if(!stk.empty()) stk.pop();
        }
        else if(word == ".")
        {
            continue;
        }
        else
        {
            stk.push(word);
        }
    }
    string res;
    while(!stk.empty())
    {
        res = '/' + stk.top() + res;
        stk.pop();
    }
    if(res == "") res = "/";
    return res;
}
```

# Notes

get single word from long string 

```c++
    istringstream iss(path);
    string word;
    while (iss >> word)
```

