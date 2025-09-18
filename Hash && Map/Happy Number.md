# Problem

Starting with any positive integer, replace the number by the sum of the squares of its digits.

Repeat the process until the number equals 1 (where it will stay), or it **loops endlessly in a cycle** which does not include 1.

Those numbers for which this process **ends in 1** are happy.

[Happy Number - LeetCode](https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Force:  use hash to store the number is appeared

Optimized: use fast and slow pointer.

# Complexity

Force Time: O(logn) Space: O(logn)

Optimized: O(logn) Space: O(1)

# Code

```c++
//force
bool isHappy(int n) {
    unordered_set<int> map;
    while(1)
    {
        if(n == 1) return true;
        if(map.count(n)) return false;
        map.insert(n);
        int res = 0;
        while(n)
        {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        n = res;
    }
    return true;
}
//optimized
int getNext(int n) {
    int res = 0;
    while (n) {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}

bool isHappy(int n) {
    int slow = n, fast = getNext(n);
    while (fast != 1 && slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    return fast == 1;
}
```
