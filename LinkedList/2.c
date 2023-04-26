// 2. Add Two Numbers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *result = malloc(sizeof(struct ListNode));
    struct ListNode *ptr = result;
    int carry = 0;
    result->val = 0;
    result->next = NULL;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int a = (l1 == NULL) ? 0 : l1->val;
        int b = (l2 == NULL) ? 0 : l2->val;

        ptr->val = a + b + carry;

        carry = ptr->val / 10; // Over 10 or not
        ptr->val = ptr->val % 10;

        // Is there a next node?
        if (l1 != NULL)
        {
            l1 = (l1->next == NULL) ? NULL : l1->next;
        }
        if (l2 != NULL)
        {
            l2 = (l2->next == NULL) ? NULL : l2->next;
        }

        // If there is the next node, then prepare the space for it.  
        if (l1 != NULL || l2 != NULL || carry != 0)
        {
            ptr->next = malloc(sizeof(struct ListNode));
            ptr->next->next = NULL;
            ptr = ptr->next;
        }
    }
    return result;
}

// ref: https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1228/