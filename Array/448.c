// 448. Find All Numbers Disappeared in an Array

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
    int i, j = 0, newi = 0;
    for (i = 0; i < numsSize; ++i)
    {
        newi = abs(nums[i]) - 1;
        nums[newi] = abs(nums[newi]) * -1;
    }

    *returnSize = 0;
    for (i = 0; i < numsSize; ++i)
    {
        if (nums[i] > 0)
        {
            ++*returnSize;
            nums[j++] = i + 1;
        }
    }
    return nums;
}
// ref: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/solutions/3156987/c-beats-100-memory-o-2n-o-1/?page=3&languageTags=c