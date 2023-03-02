// 1299. Replace Elements with Greatest Element on Right Side

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *replaceElements(int *arr, int arrSize, int *returnSize)
{
	*returnSize = arrSize;
	int i, maxNew, maxRight = -1;

	for (i = arrSize - 1; i >= 0; i--)
	{
		if (arr[i] > maxRight)
		{
			maxNew = arr[i];
		}
		arr[i] = maxRight;
		maxRight = maxNew;
	}
	return arr;

	// Time Limit Exceeded
	/*
		*returnSize = arrSize;
		int i, j, max;

		if (arrSize < 2)
		{
			arr[0] = -1;
			return arr;
		}
		for (i = 1; i < arrSize; i++)
		{
			max = arr[i];
			for (j = i + 1; j < arrSize; j++)
			{
				if (arr[j] > max)
				{
					max = arr[j];
				}
			}
			arr[i - 1] = max;
		}
		arr[arrSize - 1] = -1;
		return arr;
	*/
}