# Problem

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return *the reversed list*.

[Reverse Linked List II - LeetCode](https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

3 pointer reverse

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* pre = &dummy;
    for (int i = 1; i < left; ++i) pre = pre->next;
    ListNode* cur = pre->next;
    for (int i = 0; i < right - left; ++i) {
        ListNode* temp = cur->next;
        cur->next = temp->next;
        temp->next = pre->next;
        pre->next = temp;
    }
    return dummy.next;
}
```
