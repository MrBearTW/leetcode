// 118. Pascal's Triangle

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
    int i;
    int **ans = malloc(numRows * sizeof(int *));
    *returnSize = numRows;
    *returnColumnSizes = malloc(*returnSize * sizeof(int));

    // set column size
    for (int i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = i + 1;
    }
    // set first(0) and last(i)
    for (int i = 0; i < *returnSize; i++)
    {
        ans[i] = malloc((*returnSize) * sizeof(int));
        ans[i][0] = 1;
        ans[i][i] = 1;
    }

    for (int i = 0; i < *returnSize; i++)
    {
        for (int k = 1; k < i; k++)
        {
            ans[i][k] = ans[(i - 1)][(k - 1)] + ans[(i - 1)][k];
        }
    }
    return ans;
}

// ref: https://leetcode.com/problems/pascals-triangle/solutions/2883954/c-ezpz-beats-100/?page=2&languageTags=c