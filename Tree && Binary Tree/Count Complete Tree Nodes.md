# Problem

Given the `root` of a **complete** binary tree, return the number of the nodes in the tree.

[Count Complete Tree Nodes - LeetCode](https://leetcode.com/problems/count-complete-tree-nodes/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

force : DFS

optimized: because it is a complete binary tree, so if left heigh is equal to right heigh then just use `(1 << hl) - 1` to calculate numbers of nodes.

# Complexity

force : Time: O(n) Space: O(h)

optimized: Time: O((logn)^2) Space: O(logn)

# Code

```c++
// force 
int dfs(TreeNode* root)
{
    if(root->left && root->right)
    {
        return dfs(root->left) + dfs(root->right) + 1;
    }
    else if(root->left) return dfs(root->left) + 1;
    else if(root->right) return dfs(root->right) + 1;
    else return 1;
    return 0;
}
int countNodes(TreeNode* root) {
    if(!root) return 0;
    return dfs(root);

}
// optimized
int countNodes(TreeNode* root) {
    if (!root) return 0;
    TreeNode* l = root, *r = root;
    int hl = 0, hr = 0;
    while (l) { hl++; l = l->left; }
    while (r) { hr++; r = r->right; }
    if (hl == hr) return (1 << hl) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
```

# Notes

Don't forget add root(+ 1) 

when left heigh is equal to right heigh then number of node is  `if (hl == hr) return (1 << hl) - 1;`

