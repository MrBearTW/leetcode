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

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    int length = 1, i;
    struct ListNode *temp = head;

    while (temp->next != NULL)
    {
        length++;
        temp = temp->next;
    }

    if (length == 1)
    {
        head = NULL;
        return head;
    }

    struct ListNode *ptr;
    temp = head;

    if (n == 1)
    {
        for (i = 1; i <= length - 1; i++)
        {
            ptr = temp;
            temp = temp->next;
        }
        free(temp);
        ptr->next = NULL;
        return head;
    }
    else if (n > 1 && n < length)
    {
        for (i = 1; i <= (length - n); i++)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = temp->next;
        free(temp);
        ptr = head;
        return head;
    }
    else
    {
        head = head->next;
        free(temp);
        return head;
    }
    return head;
}


// ref: https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/2884005/c-linkedlist-more-like-easylist/?languageTags=c