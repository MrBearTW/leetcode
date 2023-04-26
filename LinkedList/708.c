// 708. Insert into a Sorted Circular Linked List

// ref: https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/solutions/2088811/c-time-space-69-nice/?orderBy=most_votes&languageTags=c

struct Node
{
    int val;
    struct TreeNode *next;
};

struct Node *insert(struct Node *head, int insertVal)
{
    struct Node *curNode = head, *prevNode = NULL, *tailNode = NULL, *nearestSmall = NULL, *nearestLarge = NULL;
    int circle = 1;

    // When head == NULL
    if (head == NULL)
    {
        curNode = (struct Node *)malloc(sizeof(struct Node));
        curNode->val = insertVal;
        curNode->next = curNode;

        return curNode;
    }


    // Find cycles head
    while (circle)
    {
        // Track the largest (Tail) Node
        if (!tailNode || (curNode->val) >= (tailNode->val))
        {
            tailNode = curNode;
        }

        // Find nearest value that is larger than insertVal
        if ((curNode->val) > insertVal)
        {
            if (!nearestLarge || (curNode->val) < (nearestLarge->val))
            {
                nearestLarge = curNode;
                nearestSmall = prevNode;
            }
        }

        // Last node before it cycles
        if ((curNode->next) == head)
        {
            // Special cases: inserting smallest or largest value
            if (!nearestSmall && !nearestLarge)
            {
                nearestSmall = tailNode;
                nearestLarge = (tailNode->next);
            }
            else if (!nearestSmall)
            {
                nearestSmall = curNode;
            }
            circle = 0;
        }

        prevNode = curNode;
        curNode = (curNode->next);
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode)
    {
        newNode->val = insertVal;
        newNode->next = nearestLarge;
        nearestSmall->next = newNode;
    }

    return head;
}

