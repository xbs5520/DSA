# Problem

Given the `root` of a binary tree, *determine if it is a valid binary search tree (BST)*.

[Validate Binary Search Tree - LeetCode](https://leetcode.com/problems/validate-binary-search-tree/?envType=study-plan-v2&envId=top-interview-150)

# Approach

DFS with in-order

# Complexity

Time: O(n)

Space: O(h)

# Code

```c++
long pre = LONG_MIN;
bool dfs(TreeNode* root)
{
    if(!root) return true;
    if(!dfs(root->left)) return false;
    if(pre >= root->val) return false;
    pre = root->val;
    return dfs(root->right);
}
bool isValidBST(TreeNode* root) {
    return dfs(root);
}
```
