// 747. Largest Number At Least Twice of Others
int dominantIndex(int *nums, int numsSize)
{
    int i, max1 = -1, max2 = -1, temp, max1i = -1, max2i = -1;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > max2 && nums[i] > max1)
        {
            max2 = max1;
            max1 = nums[i];
            max1i = i;
        }
        else if (nums[i] > max2)
        {
            max2 = nums[i];
        }
    }
    if (max1 / 2 >= max2)
    {
        return max1i;
    }
    else
    {
        return -1;
    }
}

// if (max1 / max2 >= 2 && max2 != 0) //Line 20: Char 14: runtime error: division by zero [solution.c]