// 189. Rotate Array

void rotate(int *nums, int numsSize, int k)
{
    int i, temp;
    int *ans = malloc(numsSize * sizeof(int));

    for (i = 0; i < numsSize; i++)
    {
        ans[(i + k) % numsSize] = nums[i];
    }
    for (i = 0; i < numsSize; i++)
    {
        nums[i] = ans[i];
    }
}