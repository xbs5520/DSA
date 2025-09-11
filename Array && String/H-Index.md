# Problem

H means published at least `h` papers that have each been cited at least `h` times.

[H-Index - LeetCode](https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

sort(greater) then find number > index (Because index start from 0)

record times for every papers. And find number > index form back.

# Complexity

sort -- Time: O(nlogn) Space: O(1)

record -- Time: O(n) Space: O(n)

# Code

```c++
// sort
int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int i = 0;
    for(; i < citations.size(); i++)
    {
        if(citations[i] <= i) break;
    }
    return i;
}
// record
int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for(int c : citations)
        {
            if(c >= n) count[n]++;
            else count[c]++;
        }
        int total = 0;
        for(int i = n; i >= 0; --i)
        {
            total += count[i];
            if(total >= i) return i;
        }
        return 0;
}
```
