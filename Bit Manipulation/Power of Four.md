---
id: LC342
title: Power of Four
primary_pattern: bit operation
secondary_patterns: []
status: DRAFT
time_min: 8
bugs: 0
looked_solution: true
revisit: 2025-10-09
---

# Problem

Given an integer `n`, return *`true` if it is a power of four. Otherwise, return `false`*.

An integer `n` is a power of four, if there exists an integer `x` such that `n == 4x`.

# Core Idea

first it is power of 2 && 1 just show bits at odd positions

1 -> 01   4 -> 100  16 -> 10000

# Invariant / Key Condition

 n & 0x55555555 != 0 --> if 1 bits at odd positions or not

--> 0101 0101

# Complexity

Time: O(1) 

Space: O(1) 

# Pitfall

forget must  n > 0

# Code

```c++
bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
}
```
