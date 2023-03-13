// 1051. Height Checker
int heightChecker(int *heights, int heightsSize)
{
    int i, tempi = 0, min, w, count = 0;
    int ans[heightsSize], heightsCopy[heightsSize];

    for (i = 0; i < heightsSize; i++)
    {
        heightsCopy[i] = heights[i];
    }


    for (w = 0; w < heightsSize; w++)
    {
        min = 101;
        for (i = 0; i < heightsSize; i++)
        {
            if (heights[i] < min)
            {
                min = heights[i];
                tempi = i;
            }
        }
        ans[w] = heights[tempi];
        heights[tempi] = 101;
    }

    for (i = 0; i < heightsSize; i++)
    {
        if (heightsCopy[i] != ans[i])
        {
            count++;
        }
    }
    return count;
}

// ref: https://leetcode.com/problems/height-checker/solutions/3140828/faster-than-100-c-solution/?languageTags=c