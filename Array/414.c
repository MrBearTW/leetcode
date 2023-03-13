// 414. Third Maximum Number

int thirdMax(int *nums, int numsSize)
{
    int i, j, tempmax, count = 1, max3;
    for (i = 0; i < numsSize; i++)
    {
        tempmax = 0;
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] < nums[j])
            {
                tempmax = nums[j];
                nums[j] = nums[i];
                nums[i] = tempmax;
            }
        }
    }
    if (numsSize < 3)
    {
        return nums[0];
    }
    else
    {
        for (i = 0; i < numsSize - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                count++;
            }
            if (count == 3)
            {
                max3 = i + 1;
            }
        }
        if (count < 3)
        {
            return nums[0];
        }
        return nums[max3];
    }
}

// ref:  https://leetcode.com/problems/third-maximum-number/solutions/3097798/c-solution/?page=3&languageTags=cww`1!1