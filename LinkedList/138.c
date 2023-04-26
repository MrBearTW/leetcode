// 138. Copy List with Random Pointer

// ref: https://leetcode.com/problems/copy-list-with-random-pointer/solutions/2331483/c-solution-o-1-space-compexitiy-visualised-beats-100/?orderBy=most_votes&page=5&languageTags=c

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node
{
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node *copyRandomList(struct Node *head)
{
    struct Node *newHead = NULL, *tail = NULL, *curr;

    for (curr = head; curr; curr = curr->next->next)
    {
        struct Node *new = malloc(sizeof(struct Node));
        new->next = curr->next;
        new->val = curr->val;
        curr->next = new;
    }

    for(curr = head; curr; curr = curr->next->next)
    {
        if (curr->random == NULL)
        {
            curr->next->random = NULL;
        }else
        {
            curr->next->random = curr->random->next;
        }
    }

    curr = head;

    while (curr)
    {
        struct Node *newList = curr->next;
        curr->next = newList->next;
        if(!newHead)
        {
            newHead = newList;
        }
        else
        {
            tail->next = newList;
        }
        tail = newList;
        curr = curr->next;
    }
    
    return newHead;
}
