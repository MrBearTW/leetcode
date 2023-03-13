// 977. Squares of a Sorted Array

int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    int *ans = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int i, right = numsSize - 1, left = 0;

    for (i = numsSize - 1; i >= 0; i--)
    {
        if (nums[left] * nums[left] < nums[right] * nums[right])
        {
            ans[i] = nums[right] * nums[right];
            right--;
        }
        else
        {
            ans[i] = nums[left] * nums[left];
            left++;
        }
    }
    return ans;

    // Time Limit Exceeded
    /*
        for (i = 0; i < numsSize; i++)
        {
            nums[i] = nums[i] * nums[i];
        }

        for (j = 0; j < numsSize; j++)
        {
            for (i = j + 1; i < numsSize; i++)
            {
                if (nums[j] > nums[i])
                {
                    temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                    res[j] = nums[j];
                }
            }
        }
        return nums;
    */
}

// ref: https://leetcode.com/problems/squares-of-a-sorted-array/solutions/1873182/c-easy-solution-100-o-n/?page=2&languageTags=c