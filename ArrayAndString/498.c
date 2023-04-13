// 498. Diagonal Traverse

int *findDiagonalOrder(int **mat, int matSize, int *matColSize, int *returnSize)
{
    int rSize = matSize;
    int cSize = matColSize[0];
    int r = 0;
    int c = 0;
    *returnSize = rSize * cSize;
    int *ans = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++)
    {
        ans[i] = mat[r][c];
        if ((r + c) % 2 == 0)
        {
            if (r >= 1 && c < cSize)
            {
                r--;
                c++;
            }
            else if (c < cSize)
            {
                c++;
            }
            else
            {
                r++;
            }
        }
        else
        {
            if (c >= 1 && r < rSize)
            {
                c--;
                r++;
            }
            else if (r < rSize)
            {
                r++;
            }
            else
            {
                c++;
            }
        }
    }
    return ans;
}

// ref: https://leetcode.com/problems/diagonal-traverse/solutions/2860406/fully-commented-concise-c-solution-o-n-m-time-o-1-space/?page=2&languageTags=c