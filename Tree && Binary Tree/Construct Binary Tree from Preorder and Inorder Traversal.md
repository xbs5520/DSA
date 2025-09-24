# Problem

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return *the binary tree*.

[Construct Binary Tree from Preorder and Inorder Traversal - LeetCode](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/?envType=study-plan-v2&envId=top-interview-150)

# Approach

DFS, pre-order‘s first is root, find root index in in-order its left is left tree, its right is right tree. 

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
unordered_map<int, int> hash;
TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir)
{
    if(pl > pr) return NULL;
    int rootval = preorder[pl];
    int idx = hash[rootval];
    TreeNode* root = new TreeNode(rootval);
    root->left = dfs(preorder, inorder, pl + 1, pl + idx - il, il, idx - 1);
    root->right = dfs(preorder, inorder,pl + idx - il + 1, pr, idx + 1, ir);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for(int i = 0; i < inorder.size(); i++) hash[inorder[i]] = i;
    return dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}
```

# Notes

if not clear, just draw a picture about it!
