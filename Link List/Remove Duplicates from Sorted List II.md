# Problem

Given the `head` of a sorted linked list, *delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list*. Return *the linked list **sorted** as well*.

 [Remove Duplicates from Sorted List II - LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

observe next 2 pointer , if these are duplicates then deal with them.

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *cur = dummy;
    while(cur->next && cur->next->next)
    {
        if(cur->next->val != cur->next->next->val) cur = cur->next;
        else
        {
            ListNode *N = cur->next;
            while(N && N->next && N->val == N->next->val)
            {
                N = N->next;
            }
            cur->next = N->next;
            //when delete a set of Duplicates do not go next!
        }
    }
    return dummy->next;
}
```

# Notes

cur must from dummy, because the first one might be deleted.

when delete a set of Duplicates do not go next!
