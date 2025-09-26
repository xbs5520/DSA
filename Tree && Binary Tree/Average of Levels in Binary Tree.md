# Problem

Given the `root` of a binary tree, return *the average value of the nodes on each level in the form of an array*. Answers within `10-5` of the actual answer will be accepted.

[Average of Levels in Binary Tree - LeetCode](https://leetcode.com/problems/average-of-levels-in-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

BFS

# Complexity

Time: O(n)

Space: O(m)  m - max width

# Code

```c++
vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    queue<TreeNode*> que;
    if(!root) return res;
    que.push(root);
    while(que.size())
    {
        int cnt = que.size();
        TreeNode* cur = NULL;
        long long sum = 0;
        for(int i = 0; i < cnt; i++)
        {
            cur = que.front(); que.pop();
            sum += cur->val;
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        res.push_back((double)sum / cnt);
    }
    return res;
}
```
