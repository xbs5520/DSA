# Problem

Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return *the values of the nodes you can see ordered from top to bottom*.

[Binary Tree Right Side View - LeetCode](https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Force: BFS

Optimized: DFS  -- right - left - mid

# Complexity

BFS Time: O(n) Space: O(n)

DFS Time: O(n) Space: O(h)

# Code

```c++
// BFS
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> que;
    if(!root) return res;
    que.push(root);
    while(que.size())
    {
        int cnt = que.size();
        TreeNode* cur = NULL;
        for(int i = 0; i < cnt; i++)
        {
            cur = que.front(); que.pop();
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        res.push_back(cur->val);
    }
    return res;
}
// DFS
vector<int> res;
void dfs(TreeNode* root, int d)
{
    if (!root) return;
    if (d == res.size()) res.push_back(root->val);
    dfs(root->right, d + 1);
    dfs(root->left, d + 1);
}
vector<int> rightSideView(TreeNode* root) {
    dfs(root, 0);
    return res;
}
```
