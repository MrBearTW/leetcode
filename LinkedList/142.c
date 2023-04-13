// 142. Linked List Cycle II

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

struct ListNode *detectCycle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    struct ListNode *slowptr = head;
    struct ListNode *fastptr = head;
    struct ListNode *entryptr = head;

    while (fastptr->next && fastptr->next->next)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;

        if (slowptr == fastptr)
        {
            while (slowptr != entryptr) // ???
            {
                slowptr = slowptr->next;
                entryptr = entryptr->next;
            }
            return entryptr;
        }
    }
    return NULL;
}

// ref:
// https://leetcode.com/problems/linked-list-cycle-ii/editorial/
// https://leetcode.com/problems/linked-list-cycle-ii/solutions/3359549/solution-in-c/?page=7&languageTags=c
// https://leetcode.com/problems/linked-list-cycle-ii/solutions/1701499/proof-with-image/