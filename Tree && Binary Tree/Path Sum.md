# Problem

Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.

[Path Sum - LeetCode](https://leetcode.com/problems/path-sum/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

DFS every time value decrease root value

# Complexity

Time: O(n)

Space: O(h)

# Code

```c++
bool dfs(TreeNode* root, int val)
{
    if(root->left && root->right)
    {
        return dfs(root->left, val - root->left->val) || dfs(root->right, val - root->right->val);
    }
    else if(root->left)
    {
        return dfs(root->left, val - root->left->val);
    }
    else if(root->right)
    {
        return dfs(root->right, val - root->right->val);
    }
    else
    {
        return val == 0;
    }
    return val == 0;
}
bool hasPathSum(TreeNode* root, int targetSum) {
    if(!root) return false;
    return dfs(root, targetSum - root->val);
}
```
