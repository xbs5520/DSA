# Problem

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.

Initially, all next pointers are set to `NULL`.

[Populating Next Right Pointers in Each Node II - LeetCode](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Use queue to store BFS, every level set next pointer one by one and push left/right tree of them to end of queue. 

# Complexity

Time: O(n)

Space: O(n)

# Code

```c++
    Node* connect(Node* root) {
        queue<Node*> stk;
        if(root != NULL) stk.push(root);
        while(stk.size())
        {
            int Size = stk.size();
            Node* pre = NULL;
            for(int i = 0; i < Size; i++)
            {
                Node* node = stk.front(); stk.pop();
                if(pre) pre->next = node;
                pre = node;
                if(node->left) stk.push(node->left);
                if(node->right) stk.push(node->right);
            }
            pre->next = NULL;
        }
        return root;
    }
```
