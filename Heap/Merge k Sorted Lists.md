---
id: LC23
title: Merge k Sorted Lists
primary_pattern: Min heap
secondary_patterns: []
status: DRAFT
time_min: 10
bugs: 0
looked_solution: 0
revisit: 2025-10-15
---

# Problem

Merge all the linked-lists into one sorted linked-list and return it.

# Core Idea

put every node into min-heap and create new list with every top

# Invariant / Key Condition

every get top of min-heap and push next node to heap

# Complexity

Time: O(n log k) 

Space: O(n) 

# Code

```c++
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Cmp> minHeap;
    for (auto node : lists) {
        if (node) minHeap.push(node);
    }
    ListNode dummy(0), *tail = &dummy;
    while (!minHeap.empty()) {
        ListNode* node = minHeap.top(); minHeap.pop();
        tail->next = node; tail = node;
        if (node->next) minHeap.push(node->next);
    }
    return dummy.next;
}
```
