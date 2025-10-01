# Problem

Given a positive integer `n`, write a function that returns the number of set bits in its binary representation (also known as the [Hamming weight](http://en.wikipedia.org/wiki/Hamming_weight)).

[Number of 1 Bits - LeetCode](https://leetcode.com/problems/number-of-1-bits/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

force right shift every time && check the first bit is 1 or not

optimized Brian Kernighan 

# Complexity

force Time: O(k) Space: O(1)   k -- bits count of number

Brian Kernighan  Time: O(m) Space: O(1)  m -- 1 bits count of number

# Code

```c++
//force
int hammingWeight(int n) {
    int res = 0;
    while(n) 
    {
        if(n & 1) res++;
        n >>= 1;
    }
    return res; 
}
//Brian Kernighan
int hammingWeight(int n) {
    int res = 0;
    while (n) {
        n &= (n - 1);	
        //1 time clear the lowest 1bit
        // 1100 & 1011 -> 1000
        // 1101 & 1100 -> 1100
        res++;
    }
    return res;
}
```
