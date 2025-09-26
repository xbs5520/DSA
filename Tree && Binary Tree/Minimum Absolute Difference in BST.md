# Problem

Given the `root` of a Binary Search Tree (BST), return *the minimum absolute difference between the values of any two different nodes in the tree*.

[Minimum Absolute Difference in BST - LeetCode](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

DFS(in-order)

# Complexity

Time: O(n)

Space: O(h)

# Code

```c++
int res = INT_MAX, prev = -1;
void dfs(TreeNode* root)
{
    if(!root) return;
    dfs(root->left);
    if(prev != -1) res = min(res, root->val - prev);
    prev = root->val;
    dfs(root->right);
}
int getMinimumDifference(TreeNode* root) {
    dfs(root);
    return res;
}
```

# Notes

**Binary Search Tree (BST)** 

every left < root < right.

using in-order you can get increase-array

