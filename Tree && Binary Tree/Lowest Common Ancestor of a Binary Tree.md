# Problem

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

[Lowest Common Ancestor of a Binary Tree - LeetCode](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

DFS find p and q int root->left and root->left, if find them separately. then return root;

if not they will both be found in same tree.

if `root == p || root == q` return root;

# Complexity

Time: O(n)

Space: O(h)

# Code

```c++
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q) return root;
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    if(l && r) return root;
    return l ? l : r;
}
```
