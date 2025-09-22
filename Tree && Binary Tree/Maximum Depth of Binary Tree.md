# Problem

Given the `root` of a binary tree, return *its maximum depth*.

[Maximum Depth of Binary Tree - LeetCode](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

DFS

# Complexity

Time: O(n)

Space: O(h)   --- Depth of tree

# Code

```c++
int maxDepth(TreeNode* root) {
    if(!root) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    int a = 0, b = 0;
    if(root->left) a = maxDepth(root->left);
    if(root->right) b = maxDepth(root->right);
    return max(a, b) + 1;
}
```
