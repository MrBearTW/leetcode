// 61. Rotate List

// ref: https://leetcode.com/problems/rotate-list/solutions/883079/c-o-n-solution-with-explanations/?orderBy=most_votes&page=3&languageTags=c

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

// get list length
int GetLength(struct ListNode *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return 1 + GetLength(head->next);
}

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    int length = 0, tempLength = 0;

    if (head == NULL || k == 0)
    {
        return head;
    }

    length = GetLength(head);

    if (length == 1)
    {
        return head;
    }

    k %= length;


    while (k > 0)
    {
        struct ListNode *secondLastNode = head;
        tempLength = length;
        
        // get secondLastNode
        while (tempLength - 2 > 0)
        {
            secondLastNode = secondLastNode->next;
            tempLength--;
        }
        
        secondLastNode->next->next = head;
        head = secondLastNode->next;
        secondLastNode->next = NULL;
        
        k--;
    }
    return head;
}