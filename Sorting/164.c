// 164. Maximum Gap
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int maximumGap(int *nums, int numsSize)
{
    int i, maxGap = 0;

    if (numsSize < 2)
    {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i + 1] - nums[i] > maxGap)
        {
            maxGap = nums[i + 1] - nums[i];
        }
    }
    return maxGap;
}