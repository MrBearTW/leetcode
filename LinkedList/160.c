// 160. Intersection of Two Linked Lists

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

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{

    struct ListNode *p = headA;
    struct ListNode *q = headB;

    while (p != q)  // Is pointer
    {
        if (p != NULL)
        {
            p = p->next;
        }
        else
        {
            p = headB;
        }

        if (q != NULL)
        {
            q = q->next;
        }
        else
        {
            q = headA;
        }
    }
    return q;
}

// No intersection ???

//ref:
// https://leetcode.com/problems/intersection-of-two-linked-lists/solutions/2959322/simple-code-in-c/
