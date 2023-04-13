// 66. Plus One

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int i, j, all9 = 1;
    int *ans = malloc(sizeof(int) * (digitsSize + 1));

    for (i = digitsSize - 1; i >= 0; i--)
    {
        if (digits[i] + all9 > 9)
        {
            digits[i] = 0;
            all9 = 1;
        }
        else
        {
            digits[i] = digits[i] + all9;
            all9 = 0;
        }
    }
    if (all9)
    {
        ans[0] = 1;
    }
    for (i = all9, j = 0; j < digitsSize; i++, j++)
    {
        ans[i] = digits[j];
    }
    *returnSize = digitsSize + all9;
    return ans;
}

// ref: https://leetcode.com/problems/plus-one/solutions/1966977/c-100-fast-solution-o-n/?page=4&languageTags=c