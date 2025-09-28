# Problem

Given the `root` of a binary search tree, and an integer `k`, return *the* `kth` *smallest value (**1-indexed**) of all the values of the nodes in the tree*.

[Kth Smallest Element in a BST - LeetCode](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

DFS with in-order

# Complexity

Time: O(h + k)

Space: O(h)

# Code

```c++
int cnt = 0;
int res = -1;
void dfs(TreeNode* root, int k)
{
    if(!root)
    {
        return;
    }
    dfs(root->left, k); 
    if(k == ++cnt) 
    {
        res = root->val;
    }
    dfs(root->right, k);

}
int kthSmallest(TreeNode* root, int k) {
    if(!root) return 0;
    dfs(root, k);
    return res;
}
```
