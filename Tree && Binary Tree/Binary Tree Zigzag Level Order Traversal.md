# Problem

Given the `root` of a binary tree, return *the zigzag level order traversal of its nodes' values*. (i.e., from left to right, then right to left for the next level and alternate between).

[Binary Tree Zigzag Level Order Traversal - LeetCode](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

A: BFS

B:  use deque or 2 stack(queue)

# Complexity

BFS Time: O(n) Space: O(m)

deque Time: O(n) Space: O(m)

# Code

```c++
// BFS
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> que;
    que.push(root);
    bool flag = false;
    while(que.size())
    {
        int cnt = que.size();
        TreeNode* cur = NULL;
        vector<int> ThisLevel(cnt);
        for(int i = 0; i < cnt; i++)
        {
            cur = que.front(); que.pop();
            int idx = flag ? cnt - 1 - i : i;
            ThisLevel[idx] = cur->val;
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        flag = !flag;
        res.push_back(ThisLevel);
    } 
    return res;
}
// deque
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    deque<TreeNode*> dq;
    dq.push_back(root);
    bool leftToRight = true;
    while (!dq.empty()) {
        int sz = dq.size();
        vector<int> level;
        for (int i = 0; i < sz; ++i) {
            if (leftToRight) {
                TreeNode* node = dq.front(); dq.pop_front();
                level.push_back(node->val);
                if (node->left) dq.push_back(node->left);
                if (node->right) dq.push_back(node->right);
            } else {
                TreeNode* node = dq.back(); dq.pop_back();
                level.push_back(node->val);
                if (node->right) dq.push_front(node->right);
                if (node->left) dq.push_front(node->left);
            }
        }
        res.push_back(level);
        leftToRight = !leftToRight;
    }
    return res;
}
```
