---
id: LC231
title: Power of Two
primary_pattern: bit Operations
secondary_patterns: []
status: DRAFT
time_min: 4
bugs: 0
looked_solution: true
revisit: 2025-10-09
---

# Problem

Given an integer `n`, return *`true` if it is a power of two. Otherwise, return `false`*.

An integer `n` is a power of two, if there exists an integer `x` such that `n == 2x`.

# Core Idea

if it is 1000.. then it is true

# Invariant / Key Condition

1000 - 1 =  0111

1000 & 0111 = 0

# Complexity

Time: O(1) 

Space: O(1) 

# Pitfall

forget to -numbers and 0

# Code

```c++
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```
