# Problem

Merge 2 non-decreasing Array to a non-decreasing Array. Put into First Array. 

[Merge Sorted Array - LeetCode](https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150)

# Approach

put array together and sort.

Optimized: 2-pointer -- find biggest num and put into end of First Array.

# Complexity

Sort: Time: O(n log n) Space: O(1)

Optimized: Time: O(n) Space: O(1)

# Code

Sort

```c++
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i = m; i < m + n; i++)
    {
        nums1[i] = nums2[i - m];
    }
    sort(nums1.begin(), nums1.end());
}
```



2-pointer

```c++
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int k = m + n - 1;
    int i = m - 1, j = n - 1;
    while(i >= 0 && j >= 0)
    {
        if(nums1[i] >= nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
    while(i >= 0) nums1[k--] = nums1[i--];
    while(j >= 0) nums1[k--] = nums2[j--];
} 
```

# Notes

boundary handling
