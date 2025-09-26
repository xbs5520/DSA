# Problem

Given the `root` of a binary tree, return *the level order traversal of its nodes' values*. (i.e., from left to right, level by level).

[Binary Tree Level Order Traversal - LeetCode](https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

BFS

# Complexity

Time: O(n)

Space: O(m)

# Code

```c++
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if(!root) return res;
    que.push(root);
    while(que.size())
    {
        int cnt = que.size();
        TreeNode* cur = NULL;
        vector<int> thisLevel;
        for(int i = 0; i < cnt; i++)
        {
            cur = que.front(); que.pop();
            thisLevel.push_back(cur->val);
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        res.push_back(thisLevel);
    }
    return res;
}
```
