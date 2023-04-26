// 328. Odd Even Linked List

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

struct ListNode *oddEvenList(struct ListNode *head)
{
    if (head)
    {
        struct ListNode *odd_curr = head;
        struct ListNode *even_curr = head->next;
        struct ListNode *even_head = head->next;
        // odd_head = head

        while (even_curr && even_curr->next) // odd_curr->next->next == even_curr->next
        {
            // Get new next
            odd_curr->next = odd_curr->next->next;
            even_curr->next = even_curr->next->next;
            
            // Set to next
            odd_curr = odd_curr->next;
            even_curr = even_curr->next;
        }
        // odd + even
        odd_curr->next = even_head;
    }
    return head;
}

// ref: https://leetcode.com/problems/odd-even-linked-list/solutions/1514236/c-0ms-100/?orderBy=most_votes&languageTags=c