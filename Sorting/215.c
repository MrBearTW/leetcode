// 215. Kth Largest Element in an Array




// Time Limit Exceeded 
/*
int findKthLargest(int *nums, int numsSize, int k)
{
    int i, doSwitch = 1, temp;

    while (doSwitch == 1)
    {
        doSwitch = 0;
        for (i = 1; i < numsSize; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                temp = nums[i - 1];
                nums[i - 1] = nums[i];
                nums[i] = temp;
                doSwitch = 1;
            }
        }
    }
    return nums[k - 1];
}
*/