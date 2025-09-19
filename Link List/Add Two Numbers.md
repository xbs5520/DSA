# Problem

You are given two **non-empty** linked lists representing two non-negative integers.

The digits are stored in **reverse order**

Add the two numbers and return the sum as a linked list.

# Approach

just add them. don't forget **carry**; 

# Complexity

Time: O(max(n, m))

Space: O(max(n, m))

# Code

```c++
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* node = head;
        int p = 0;
        while (l1 || l2 || p) {
            int a = p;
            if (l1) { a += l1->val; l1 = l1->next; }
            if (l2) { a += l2->val; l2 = l2->next; }
            p = a / 10;
            a %= 10;
            node->next = new ListNode(a);
            node = node->next;
        }
        return head->next;
    }
```
