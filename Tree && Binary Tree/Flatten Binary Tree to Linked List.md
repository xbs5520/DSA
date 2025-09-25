# Problem

Given the `root` of a binary tree, flatten the tree into a "linked list"

[Flatten Binary Tree to Linked List - LeetCode](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Force:  DFS use a queue store TreeNode by pre-order and link them together

Optimized: Don't

# Complexity

Force -- Time: O(n) Space: O(n)

Optimized -- Time: O(n) Space: O(1)

# Code

```c++
// force
	queue<TreeNode*> Que;
    void dfs(TreeNode* root)
    {
        if(root == NULL) return;
        Que.push(root);
        dfs(root->left);
        dfs(root->right);
    }
    void flatten(TreeNode* root) {
        dfs(root);
        TreeNode* pre = NULL;
        while(Que.size())
        {
            TreeNode* cur = Que.front(); Que.pop();
            cur->left = NULL;
            cur->right = NULL;
            if(pre)
            {
                pre->right = cur;
                pre = pre->right;
            } 
            else
            {
                pre = cur;
            }
        }
        return;
    }
// Optimized
void flatten(TreeNode* root) {
    if (!root) return;
    flatten(root->left);
    flatten(root->right);
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    root->left = nullptr;
    root->right = left;
    TreeNode* p = root;
    while (p->right) p = p->right;
    p->right = right;
}
```
