// 912. 
// Heap sort
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

int *sortArray(int *nums, int numsSize, int *returnSize)
{
    int *ans = malloc(numsSize & sizeof(int));
    *returnSize = numsSize;

    // Build max heap
    for (int i = numsSize / 2 - 1; i >= 0; i--)
        heapify(nums, numsSize, i);

    // Heap sort
    for (int i = numsSize - 1; i >= 0; i--)
    {
        swap(&nums[0], &nums[i]);

        // Heapify root element to get highest element at root again
        heapify(nums, i, 0);
    }

    return nums;
}

// ref:
// https://www.programiz.com/dsa/heap-sort
// https://leetcode.com/problems/sort-an-array/solutions/3040565/c-solution-beats-90-75-runtime/?page=2&languageTags=c