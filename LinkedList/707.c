// 707. Design Linked List

// V3
// Base on v2, try to add Doubly in answer
// ref: https://leetcode.com/explore/learn/card/linked-list/210/doubly-linked-list/1297/

// NOT DONE 

typedef struct List
{
    int val;
    struct List *next;
    struct List *prev;
} MyLinkedList;

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *result = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    result->val = -1;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

int myLinkedListGet(MyLinkedList *obj, int index)
{
    obj = obj->next;
    int count = 0;
    while (obj)
    {
        if (count == index)
        {
            return obj->val;
        }
        count++;
        obj = obj->next;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    MyLinkedList *temp = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    temp->val = val;
    temp->next = obj->next;
    obj->next = temp;
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    while (obj && obj->next)
    {
        obj = obj->next; // obj is orignal tail
    }
    MyLinkedList *temp = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    temp->val = val;
    temp->next = NULL;
    obj->next = temp;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    int count = 0;
    MyLinkedList *temp = obj;
    while (temp)
    {
        if (count == index)
        {
            MyLinkedList *cur = (MyLinkedList *)malloc(sizeof(MyLinkedList));
            cur->val = val;
            cur->next = temp->next;
            temp->next = cur;
            break;
        }
        count++;
        temp = temp->next;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    MyLinkedList *cur = obj->next, *pre = obj;
    int count = 0;
    while (cur)
    {
        if (count == index)
        {
            pre->next = cur->next;
            free(cur);
            return;
        }
        count++;
        pre = cur;
        cur = cur->next;
    }
}

void myLinkedListFree(MyLinkedList *obj)
{
    while (obj)
    {
        MyLinkedList *temp = obj;
        obj = obj->next;
        free(temp);
    }
}

// V2
// ref: https://leetcode.com/problems/design-linked-list/solutions/1569415/my-c-solution/?orderBy=most_votes&page=2&languageTags=c

/*
typedef struct List
{
    int val;
    struct List *next;
} MyLinkedList;

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *result = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    result->val = -1;
    result->next = NULL;
    return result;
}

int myLinkedListGet(MyLinkedList *obj, int index)
{
    obj = obj->next;
    int count = 0;
    while (obj)
    {
        if (count == index)
        {
            return obj->val;
        }
        count++;
        obj = obj->next;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    MyLinkedList *temp = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    temp->val = val;
    temp->next = obj->next;
    obj->next = temp;
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    while (obj && obj->next)
    {
        obj = obj->next; // obj is orignal tail
    }
    MyLinkedList *temp = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    temp->val = val;
    temp->next = NULL;
    obj->next = temp;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    int count = 0;
    MyLinkedList *temp = obj;
    while (temp)
    {
        if (count == index)
        {
            MyLinkedList *cur = (MyLinkedList *)malloc(sizeof(MyLinkedList));
            cur->val = val;
            cur->next = temp->next;
            temp->next = cur;
            break;
        }
        count++;
        temp = temp->next;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    MyLinkedList *cur = obj->next, *pre = obj;
    int count = 0;
    while (cur)
    {
        if (count == index)
        {
            pre->next = cur->next;
            free(cur);
            return;
        }
        count++;
        pre = cur;
        cur = cur->next;
    }
}

void myLinkedListFree(MyLinkedList *obj)
{
    while (obj)
    {
        MyLinkedList *temp = obj;
        obj = obj->next;
        free(temp);
    }
}
*/


// v1

/*
typedef struct Node
{
    int val;
    struct Node *next;
} node;

typedef struct
{
    node *head;
    int length;
} MyLinkedList;

node *createNode(int val)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->val = val;
    return new_node;
}

node *getNode(MyLinkedList *obj, int index)
{
    if (obj->head == NULL || index >= obj->length)
    {
        return NULL;
    }

    node *current = obj->head;
    int currentIndex = 0;

    while (currentIndex < index)
    {
        current = current->next;
        currentIndex++;
    }

    return current;
}

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *linkedList = malloc(sizeof(MyLinkedList));
    linkedList->length = 0;
    return linkedList;
}

int myLinkedListGet(MyLinkedList *obj, int index)
{
    node *nodeAtIndex = getNode(obj, index);
    return nodeAtIndex == NULL ? -1 : nodeAtIndex->val;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    myLinkedListAddAtIndex(obj, obj->length, val);
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    if (index > obj->length)
    {
        return;
    }

    node *newNode = createNode(val);

    if (index == 0)
    {
        if (obj->head == NULL)
        {
            obj->head = newNode;
        }
        else
        {
            newNode->next = obj->head;
            obj->head = newNode;
        }
    }
    else
    {
        node *nodeBefore = getNode(obj, index - 1);
        newNode->next = nodeBefore->next;
        nodeBefore->next = newNode;
    }
    obj->length++;
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    if (index >= obj->length)
    {
        return;
    }

    if (index == 0)
    {
        node *oldHead = obj->head;
        obj->head = oldHead->next;
        free(oldHead);
    }
    else
    {
        node *nodeBefore = getNode(obj, index - 1);
        node *nodeToDelete = nodeBefore->next;
        nodeBefore->next = nodeToDelete->next;
        free(nodeToDelete);
    }
    obj->length--;
}

void myLinkedListFree(MyLinkedList *obj)
{
    while (obj->length)
    {
        myLinkedListDeleteAtIndex(obj, 0);
    }
}
*/

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/