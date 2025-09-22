# Problem

Given the `head` of a linked list and a value `x`, partition it such that all nodes **less than** `x` come before nodes **greater than or equal** to `x`.

[Partition List - LeetCode](https://leetcode.com/problems/partition-list/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Force: 

Optimized: 

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
ListNode* partition(ListNode* head, int x) {
    ListNode *Left = new ListNode(0);
    ListNode *Right = new ListNode(0);
    ListNode *curL = Left;
    ListNode *curR = Right;
    while(head)
    {
        ListNode *cur = head;
        head = head->next;
        if(cur->val < x)
        {
            curL->next = cur;
            curL = curL->next;
        }
        else
        {
            curR->next = cur;
            curR = curR->next;
        }
    }
    curR->next = NULL;
    curL->next = Right->next;
    return Left->next;
}
```

# Notes

`curR->next = NULL`

Must set curR'next is NULL, or it might become dead loop;

because the curR maybe not the last of original list.
