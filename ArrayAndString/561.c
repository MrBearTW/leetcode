// 561. Array Partition

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int arrayPairSum(int *nums, int numsSize)
{
    int i,sum = 0;

    qsort(nums, numsSize, sizeof(int), cmp);
    
    for (i = 0; i < numsSize; i = i + 2)
    {
        sum += nums[i];
    }

    return sum;
}

// ref: https://leetcode.com/problems/array-partition/solutions/3260013/code-in-c-easy-to-understand-beats-100-solution-please-upvote-it-if-its-help-you/?page=2&languageTags=c