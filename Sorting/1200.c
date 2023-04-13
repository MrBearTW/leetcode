// 1200. Minimum Absolute Difference

int diff(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int **minimumAbsDifference(int *arr, int arrSize, int *returnSize, int **returnColumnSizes)
{
    int min = 1000000;
    int **ans = (int **)malloc(arrSize * sizeof(int *));
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(arrSize * sizeof(int));

    qsort(arr, arrSize, sizeof(int), diff);

    for (int i = 1; i < arrSize; i++)
    {
        if (min < arr[i] - arr[i - 1])
        {
            min = min;
        }
        else
        {
            min = arr[i] - arr[i - 1];
        }
    }

    for (int i = 1; i < arrSize; i++)
        if (arr[i] - arr[i - 1] == min)
        {
            (*returnColumnSizes)[*returnSize] = 2;
            ans[*returnSize] = (int *)malloc(2 * sizeof(int));
            ans[*returnSize][0] = arr[i - 1];
            ans[*returnSize][1] = arr[i];
            (*returnSize)++;
        }

    return ans;
}

// ref:
// https://leetcode.com/problems/minimum-absolute-difference/editorial/
// https://leetcode.com/problems/minimum-absolute-difference/solutions/1636870/simple-c-solution-with-qsort-n-logn/?page=2&languageTags=c
