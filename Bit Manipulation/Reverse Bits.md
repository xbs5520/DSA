# Problem

Reverse bits of a given 32 bits signed integer.

# Approach

**Bit Manipulation**

# Complexity

Time: O(1)

Space: O(1)

# Code

```c++
int reverseBits(int n) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
        res = (res << 1) | (n & 1);
        n >>= 1;
    }
    return res;    
}
```

# Notes

n & 1 the lowest n
