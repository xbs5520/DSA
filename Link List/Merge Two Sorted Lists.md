# Problem

Merge the two lists into one **sorted** list

[Merge Two Sorted Lists - LeetCode](https://leetcode.com/problems/merge-two-sorted-lists/?envType=study-plan-v2&envId=top-interview-150)

# Approach

compare first of list link smaller one into new list.

# Complexity

Time: O(m + n)

Space: O(1)

# Code

```c++
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode * head = new ListNode();
    ListNode * node = head;
    while(list1 && list2)
    {
        if(list1->val < list2->val)
        {
            node->next = list1;
            list1 = list1->next;
        }
        else
        {
            node->next = list2;
            list2 = list2->next;
        }
        node = node->next;
    }
    if(list1) node->next = list1;
    if(list2) node->next = list2;
    return head->next;
}
```
