// 1051. Height Checker
int heightChecker(int *heights, int heightsSize)
{
    int i, p1, p2, doSwitch = 1, temp, count = 0;
    int heightsCopy[heightsSize];

    for (i = 0; i < heightsSize; i++)
    {
        heightsCopy[i] = heights[i];
    }

    while (doSwitch == 1)
    {
        doSwitch = 0;
        for (i = 1; i < heightsSize; i++)
        {
            if (heightsCopy[i - 1] > heightsCopy[i])
            {
                temp = heightsCopy[i - 1];
                heightsCopy[i - 1] = heightsCopy[i];
                heightsCopy[i] = temp;
                doSwitch = 1;
            }
        }
    }

    for (i = 0; i < heightsSize; i++)
    {
        if (heightsCopy[i] != heights[i])
        {
            count++;
        }
    }
    return count;
}

// ref: https://leetcode.com/explore/learn/card/sorting/694/comparison-based-sorts/4434/