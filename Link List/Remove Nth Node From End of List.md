# Problem

Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.

[Remove Nth Node From End of List - LeetCode](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

Find the nth of end. --> 2 pointer Let right go n times. Then go together, when right go to end, then left is nth of end.

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode * dummy = new ListNode(0);
    dummy->next = head;
    ListNode* L = dummy;
    ListNode* R = dummy;
    while(n--) R = R->next;
    while(R->next)
    {
        L = L->next;
        R = R->next;
    }
    L->next = L->next->next;
    return dummy->next;
}
```

# Notes

Must go from dummy, because the first one maybe be deleted.
