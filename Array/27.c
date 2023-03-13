// 27. Remove Element

// Approach 1: Two Pointers
int removeElement(int *nums, int numsSize, int val)
{
    int i, j = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return nums;
}

// Approach 2: Two Pointers - when elements to remove are rare
int removeElement(int *nums, int numsSize, int val)
{
    int f = 0, b = numsSize;
    while (f < b)
    {
        if (nums[f] == val)
        {
            nums[f] = nums[b - 1];
            b--;
        }
        else
        {
            f++;
        }
    }
    return f;
}

// ref: https://leetcode.com/problems/remove-element/editorial/