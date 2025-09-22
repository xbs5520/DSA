# Problem

Given the `head` of a linked list, rotate the list to the right by `k` places.

[Rotate List - LeetCode](https://leetcode.com/problems/rotate-list/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

First `K %= LinkSize` if k == 0 then return original list

then find the kth of end of list. That is the new head.

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
ListNode* rotateRight(ListNode* head, int k) {
    if(k == 0 || !head || !head->next) return head;
    int Listsize = 0;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    while(head)
    {
        head = head->next;
        Listsize++;
    }
    k %= Listsize;
    head = dummy->next;
    if(k == 0) return head;
    ListNode *Newhead = head;
    for(int i = 0; i < k; i++) head = head->next;
    while(head->next)
    {
        Newhead = Newhead->next;
        head = head->next;
    }
    ListNode *res = Newhead->next;
    // must cut this or it is a dead loop
    Newhead->next = NULL;	
    head->next = dummy->next;
    return res;
}
```

# Notes

must cut original list or it becomes a dead loop.
