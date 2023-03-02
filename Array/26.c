//  26. Remove Duplicates from Sorted Array
int removeDuplicates(int *nums, int numsSize)
{
	int i, insert = 1;
	for (i = 1; i < numsSize; i++)
	{
		if (nums[i] != nums[i - 1])
		{
			nums[insert] = nums[i];
			insert++;
		}
	}
	return insert;
}