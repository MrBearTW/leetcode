// 141. Linked List Cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head)
{
    struct ListNode *slow = head; // ???
    struct ListNode *fast = NULL; // ???

    // check ListNode only have one node.
    if (!head || !(head->next))
    {
        return false;
    }

    fast = head->next; // 2 steap?

    while (slow != fast) // Until 2 pointer match.
    {
        // One iteration
        slow = slow->next;

        if (fast->next && fast->next->next)
        {
            fast = fast->next->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}

// ref: https://leetcode.com/problems/linked-list-cycle/solutions/835202/c-implementation/