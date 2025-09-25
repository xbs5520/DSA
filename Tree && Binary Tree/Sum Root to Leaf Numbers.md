# Problem

You are given the `root` of a binary tree containing digits from `0` to `9` only.

Each root-to-leaf path in the tree represents a number.

[Sum Root to Leaf Numbers - LeetCode](https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

DFS every time `sum * 10 + root->left->val` and add them together

# Complexity

Time: O(n)

Space: O(h)

# Code

```c++
int dfs(TreeNode* root, int sum)
{
    if(root->left && root->right) 
    {
        return dfs(root->left, sum * 10 + root->left->val) + dfs(root->right, sum * 10 + root->right->val);
    }
    else if(root->left) return dfs(root->left, sum * 10 + root->left->val);
    else if(root->right) return dfs(root->right, sum * 10 + root->right->val);
    else return sum;
    return 0;
}
int sumNumbers(TreeNode* root) {
    if(!root) return 0;
    return dfs(root, root->val);
}
```

