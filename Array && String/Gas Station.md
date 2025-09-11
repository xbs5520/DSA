# Problem

There is circle station, given gas array && cost array find the start station.

[Gas Station - LeetCode](https://leetcode.com/problems/gas-station/submissions/1767695643/?envType=study-plan-v2&envId=top-interview-150)

# Approach

greedy: total += gas[i] - cost[i] if total < 0 at last then must can't go circle.

if  current += gas[i] - cost[i] < 0 then every point before is not start point. 

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0, curr = 0, start = 0;
    for (int i = 0; i < gas.size(); ++i) {
        total += gas[i] - cost[i];
        curr += gas[i] - cost[i];
        if (curr < 0) {
            start = i + 1;
            curr = 0;
        }
    }
    return total < 0 ? -1 : start;
}
```
