// 75. Sort Colors
void sortColors(int *nums, int numsSize)
{
    int p0 = 0, p2 = numsSize - 1, curr = 0, temp;
    while (curr <= p2)
    {
        if (nums[curr] == 0)
        {
            temp = nums[curr];
            nums[curr] = nums[p0];
            nums[p0] = temp;
            p0++;
            curr++;
        }
        else if (nums[curr] == 2)
        {
            temp = nums[curr];
            nums[curr] = nums[p2];
            nums[p2] = temp;
            p2--;
        }
        else
        {
            curr++;
        }
    }
}