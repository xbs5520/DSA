# Problem

Find indices of the two numbers in an array that add up to a given target.

[Two Sum - LeetCode](https://leetcode.com/problems/two-sum/)

# Approach

Force: check every pair O(n^2) Maybe sort first?

Optimized: use a hash map to store complement umbers -- index

visit current number is exist or not. O(n)

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
vector<int> twoSum(vector<int>& nums, int target) 
{
    unordered_map<int, int> hash;
    for(int i = 0; i < nums.size(); i++)
    {
            // auto it = hash.find(nums[i]);
            // if(it != hash.end())
            // {
            //     return {it->second, i};
            // }
            if(hash.count(nums[i]))
            {
                return {hash[nums[i]], i};
            }
        	
        	//add new complement number and its index 
            hash[target - nums[i]] = i;
    }
    return {0, 0};
}
```

# Notes

unordered_map:

hash.find()  -------    it -> second

hash.count   -------   hash[nums]



In an embedded context, hash maps may not always be available

sort + 2 pointer

Sort(nlogn)

2pointer(n)

Timer: O(nlogn)

Space: O(n) store original index 

```c++
// store original index
struct NumIndex {
    int val;
    int idx;
};

// quicksort
void quickSort(vector<NumIndex>& arr, int left, int right) {
    if (left >= right) return;
    int i = left, j = right;
    NumIndex pivot = arr[left];
    while (i < j) {
        while (i < j && arr[j].val >= pivot.val) j--;
        arr[i] = arr[j];
        while (i < j && arr[i].val <= pivot.val) i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

// Two Sum using sorting + two pointers
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<NumIndex> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = {nums[i], i};
    }

    quickSort(arr, 0, n - 1);

    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left].val + arr[right].val;
        if (sum == target) {
            return {arr[left].idx, arr[right].idx};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {}; // not found
}
```

