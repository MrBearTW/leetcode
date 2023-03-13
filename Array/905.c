// 905. Sort Array By Parity
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArrayByParity(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int f, b = numsSize - 1, temp, flag;

    while (f < b)
    {
        if (nums[f] % 2 > nums[b] % 2)
        {
            temp = nums[b];
            nums[b] = nums[f];
            nums[f] = temp;
        }
        if (nums[f] % 2 ==0) f++;
        if (nums[b] % 2 !=0) b--;
    }
    return nums;
}
// ref: https://leetcode.com/problems/sort-array-by-parity/editorial/