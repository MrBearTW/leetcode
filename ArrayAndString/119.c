// 119. Pascal's Triangle II

int *getRow(int rowIndex, int *returnSize)
{
    *returnSize = rowIndex + 1;
    int *ans = malloc(sizeof(int) * (*returnSize));
    int i, j;

    ans[0] = 1;

    for (i = 1; i < rowIndex + 1; i++)
    {
        ans[i] = 1;
        int temp = 1;
        for (j = 1; j < i; j++)
        {
            ans[j] = temp + ans[j];
            temp = ans[j] - temp;
        }
    }
    return ans;
}

// ref: https://leetcode.com/problems/pascals-triangle-ii/solutions/2971864/0ms-c-solution-beats-100-using-just-1-array-returnsize/