# Problem

Given the `root` of a binary tree, *check whether it is a mirror of itself* (i.e., symmetric around its center).

[Symmetric Tree - LeetCode](https://leetcode.com/problems/symmetric-tree/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

BFS

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
bool isSymmetric(TreeNode* root) {
    TreeNode *Left = root->left;
    TreeNode *Right = root->right;
    stack<TreeNode*> L, R;
    if(Left != NULL) L.push(Left);
    if(Right != NULL) R.push(Right);
    while(!L.empty() && !R.empty())
    {
        TreeNode *NodeL = L.top(); L.pop();
        TreeNode *NodeR = R.top(); R.pop();
        if (!NodeL && !NodeR) continue;
        if (!NodeL || !NodeR) return false;
        if(NodeL->val != NodeR->val) return false;
        L.push(NodeL->left);
        L.push(NodeL->right);
        R.push(NodeR->right);
        R.push(NodeR->left);
    }
    return L.empty() && R.empty();
}
```

# Notes

Must push Null to stack to compare! 
