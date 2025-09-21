# Problem

A linked list of length `n` is given such that each node contains an additional random pointer, which could point to any node in the list, or `null`.

Construct a [**deep copy**](https://en.wikipedia.org/wiki/Object_copying#Deep_copy) of the list. 

[Copy List with Random Pointer - LeetCode](https://leetcode.com/problems/copy-list-with-random-pointer/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Force:  use 2 hash to store index and node

Optimized: copy all node and their pointer next to original node.  split the list.

# Complexity

Force: Time: O(n) Space: O(n)

Optimized:  Time: O(n) Space: O(1)

# Code

```c++
//Optimized:
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    // copy pointer next to original one
    Node* cur = head;
    while (cur) {
        Node* copy = new Node(cur->val);
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }
    // cpoy random 
    cur = head;
    while (cur) {
        if (cur->random)
            cur->next->random = cur->random->next;
        cur = cur->next->next;
    }
    // split list.
    Node* dummy = new Node(0);
    Node* copyCur = dummy;
    cur = head;
    while (cur) {
        copyCur->next = cur->next;
        cur->next = cur->next->next;
        copyCur = copyCur->next;
        cur = cur->next;
    }
    return dummy->next;
}
//force
Node* copyRandomList(Node* head) {
    unordered_map<Node*, int> OldIndexofNode;
    unordered_map<Node*, int> OldNodetoIndex;
    unordered_map<int, Node*> OldIndextoNode;
    Node *newhead = new Node(0);
    Node *oldhead = new Node(0);
    oldhead->next = head;
    Node *curnew = newhead;
    Node *curold = head;
    int idx = 1;
    while(curold)
    {
        Node *NewNode = new Node(curold->val);
        OldIndextoNode[idx] = NewNode;
        OldIndexofNode[curold] = idx;
        curnew->next = NewNode;
        curnew = curnew->next;
        curold = curold->next;
        idx++;
    }
    curold = oldhead->next;
    curnew = newhead->next;
    while(curold)
    {
        curnew->random = OldIndextoNode[OldIndexofNode[curold->random]];
        curnew = curnew->next;
        curold = curold->next;
    }
    return newhead->next;
}
```
