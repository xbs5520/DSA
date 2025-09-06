# Problem

Find the circle in the list

[Linked List Cycle - LeetCode](https://leetcode.com/problems/linked-list-cycle/?envType=study-plan-v2&envId=top-interview-150)

# Approach

use a hash to record the nodes that have been visited. if a node is encountered that already exit in hash set. return true.

fast and slow pointer if they meet it is a circle there.

# Complexity

hash: Time: O(n) Space: O(n)

2pointer: Time: O(n) Space: O(1)

# Code

```c++
bool hasCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast && fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            return true;
        }

    }
    return false;
}
```
