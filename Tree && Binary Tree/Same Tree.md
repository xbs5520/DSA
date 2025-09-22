# Problem

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

[Same Tree - LeetCode](https://leetcode.com/problems/same-tree/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

DFS

# Complexity

Time: O(n)

Space: O(h)   --- Depth of tree

# Code

```c++
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    if(!p || !q) return false;
    if(p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
```
