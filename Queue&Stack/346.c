// 346. Moving Average from Data Stream

typedef struct
{
    int *data;
    int index;
    int count;
    int size;
    int sum;
} MovingAverage;

MovingAverage *movingAverageCreate(int size)
{
    MovingAverage *obj = malloc(sizeof(MovingAverage));

    memset(obj, 0, sizeof(MovingAverage));  // obj = {0};   ???

    obj->data = malloc(sizeof(int) * size);
    obj->size = size;

    return obj;
}

double movingAverageNext(MovingAverage *obj, int val)
{
    if (obj->count >= obj->size)    // If full
    {
        obj->sum -= obj->data[obj->index];
        obj->count = obj->size - 1;
    }

    obj->data[obj->index] = val;
    obj->sum += val;

    obj->index = (obj->index + 1) % obj->size;
    obj->count++;

    return (double)obj->sum / obj->count;
}

void movingAverageFree(MovingAverage *obj)
{
    free(obj->data);
    free(obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);

 * movingAverageFree(obj);
*/


// ref: https://leetcode.com/problems/moving-average-from-data-stream/solutions/1121022/c-96-faster/?languageTags=c