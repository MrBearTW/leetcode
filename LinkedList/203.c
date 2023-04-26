// 203. Remove Linked List Elements

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

struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode *cur = NULL;
    while (head != NULL && head->val == val)
    {
        head = head->next;
    }

    cur = head;
    while (cur && cur->next)
    {
        if (cur->next->val == val)
        {
            cur->next = cur->next->next;
        }
        else
        {
            cur = cur->next;
        }
    }

    return head;
}

// ref:

// https://leetcode.com/problems/remove-linked-list-elements/solutions/1957589/c-90-simple-solution-o-n/?orderBy=most_votes&page=2&languageTags=c
// 
// pointer of pointer --> https://leetcode.com/problems/remove-linked-list-elements/solutions/565756/c-and-c-quick-and-short-solutions-using-pointer-to-pointer/ 