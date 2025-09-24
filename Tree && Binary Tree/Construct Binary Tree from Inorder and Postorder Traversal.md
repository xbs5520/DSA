# Problem

Given two integer arrays `inorder` and `postorder` where `inorder` is the inorder traversal of a binary tree and `postorder` is the postorder traversal of the same tree, construct and return *the binary tree*.

[Construct Binary Tree from Inorder and Postorder Traversal - LeetCode](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/?envType=study-plan-v2&envId=top-interview-150)

# Approach

DFS, post-order‘s last is root, find root index in in-order its left is left tree, its right is right tree. 

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
unordered_map<int, int> hash;
TreeNode* dfs(vector<int>& postorder, int il, int ir, int pl, int pr)
{
    if(pl > pr) return NULL;

    int rootval = postorder[pr];
    int idx = hash[rootval];
    TreeNode *root = new TreeNode(rootval);
    root->left = dfs(postorder, il, idx - 1, pl, pl + idx - il - 1);
    root->right = dfs(postorder, idx + 1, ir, pl + idx - il, pr - 1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    for(int i = 0; i < inorder.size(); i++) hash[inorder[i]] = i;

    return dfs(postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}
```

# Notes

the right end is `pl + idx - il - 1` !! because `idx - il` is length of tree.

 -1 to get index of end point. 

 

