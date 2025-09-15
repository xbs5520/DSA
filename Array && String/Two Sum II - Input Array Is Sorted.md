# Problem

find 2 number in sorted array, the sum of them equals the target

[Two Sum II - Input Array Is Sorted - LeetCode](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

2 pointer

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    for(; i < j; )
    {
        int sum = numbers[i] + numbers[j];
        if(sum > target) j--;
        else if(sum < target) i++;
        else return {i + 1, j + 1};
    }
    return {0, 0};
}
```

