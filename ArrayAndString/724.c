// 724. Find Pivot Index

int pivotIndex(int *nums, int numsSize)
{
    int i, lsum = 0, total = 0;
    for (i = 0; i < numsSize; i++)
    {
        total += nums[i];
    }

    for (i = 0; i < numsSize; i++)
    {
        if (lsum == total - lsum - nums[i])
        {
            return i;
        }
        lsum += nums[i];
    }
    return -1;
}

// ref: https://leetcode.com/problems/find-pivot-index/solutions/2806884/c-program-to-find-pivot-index/?page=2&languageTags=c