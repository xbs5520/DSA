---
id: LC102
title: Binary Tree Level Order Traversal
primary_pattern: BFS
secondary_patterns: []
status: DRAFT
time_min: 5
bugs: 0
looked_solution: false
revisit: 2025-10-01
---

# Problem

Given the `root` of a binary tree, return *the level order traversal of its nodes' values*.

[Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150)

# Core Idea

push every level nodes into queue and process

# Invariant / Key Condition

count every level's number for not visit new pushed node.

# Complexity

Time: O(n) 

Space: O(w)  max width

# Pitfall

forget to push level's vector

don't read `que.size()` dynamicly

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
