// 707. Design Linked List

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