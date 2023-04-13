// 622. Design Circular Queue

typedef struct
{
    int size;
    int *queue;
    int readIdx;
    int writeIdx;
    int capacity;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k)
{
    MyCircularQueue *q;
    q = malloc(sizeof(MyCircularQueue));
    q->queue = malloc(sizeof(int) * k);
    q->writeIdx = 0;
    q->readIdx = 0;
    q->capacity = k;
    q->size = 0;

    return q;
}
bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
    if (obj->size == 0)
    {
        return true;
    }
    return false;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
    if (obj->size + 1 <= obj->capacity)
    {
        obj->queue[obj->writeIdx] = value;
        obj->writeIdx = (obj->writeIdx + 1) % obj->capacity;
        obj->size++;
        return true;
    }
    else
    {
        return false;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }

    obj->readIdx = (obj->readIdx + 1) % obj->capacity;
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->queue[obj->readIdx];
}

int myCircularQueueRear(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->queue[((obj->readIdx) + (obj->size - 1)) % obj->capacity];
}

bool myCircularQueueIsFull(MyCircularQueue *obj)
{
    if (obj->size == obj->capacity)
    {
        return true;
    }
    return false;
}

void myCircularQueueFree(MyCircularQueue *obj)
{
    free(obj->queue);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/