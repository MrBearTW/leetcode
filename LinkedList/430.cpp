// 430. Flatten a Multilevel Doubly Linked List

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head, Node *rest = nullptr)
    {
        // Check head is not NULL
        if (!head)
        {
            return rest;
        }

        // Deal when is child first
        head->next = flatten(head->child, flatten(head->next, rest));


        // Deal when is next
        if (head->next)
        {
            head->next->prev = head;
        }
        head->child = nullptr;
        return head;
    }
};

// ref: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/solutions/295912/c-simple-5-line-recursive-solution-with-diagram/?orderBy=most_votes&languageTags=c