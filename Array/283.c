// 283. Move Zeroes
void moveZeroes(int *nums, int numsSize)
{
    int i, count = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            nums[count++] = nums[i];
        }
    }
    for (i = count; i < numsSize; i++)
    {
        nums[i] = 0;
    }
    return nums;
}