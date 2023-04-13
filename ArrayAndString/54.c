// 54. Spiral Matrix

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{

    int i, top = 0, right = *matrixColSize - 1, bottom = matrixSize - 1, left = 0, r = 0, c = 0, direction = 0;
    *returnSize = matrixSize * (*matrixColSize);
    int *ans = malloc(sizeof(int) * (*returnSize));

    /*
    direction
    0 right
    1 down
    2 left
    3 up

    */
    for (i = 0; i < *returnSize; i++)
    {
        ans[i] = matrix[r][c];
        switch (direction)
        {
        case 0:
            if (c < right)
            {
                c++; // go right
            }
            else
            {
                r++;
                direction = 1; // turn down
                top++;
            }
            break;
        case 1:
            if (r < bottom)
            {
                r++; // go down
            }
            else
            {
                c--;
                direction = 2; // turn left
                right--;
            }
            break;
        case 2:
            if (c > left)
            {
                c--; // go left
            }
            else
            {
                r--;
                direction = 3; // turn up
                bottom--;
            }
            break;
        case 3:
            if (r > top)
            {
                r--; // go up
            }
            else
            {
                c++;
                direction = 0; // turn right
                left++;
            }
            break;

        default:
            break;
        }
    }
    return ans;
}