# Problem

check if it is a valid palindrome.

# Approach

2 Pointer

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    for(; i < j; i++, j--)
    {
        while(i < j && !isalpha(s[i]) && !isdigit(s[i])) i++;
        while(i < j && !isalpha(s[j]) && !isdigit(s[j])) j--;
        if(toupper(s[i]) != toupper(s[j])) return false;
    }
    return true;
}
```
