# Problem

Given the `root` of a binary tree, invert the tree, and return *its root*.

[Invert Binary Tree - LeetCode](https://leetcode.com/problems/invert-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

DFS

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
void dfs(TreeNode* root)
{
    if(!root) return;
    swap(root->left, root->right);
    dfs(root->left);
    dfs(root->right);
}
TreeNode* invertTree(TreeNode* root) {
    dfs(root);
    return root;
}
```

