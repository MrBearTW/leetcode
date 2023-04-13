// 14. Longest Common Prefix

char *longestCommonPrefix(char **strs, int strsSize)
{
    int i, w;

    for (w = 0;; w++)
    {
        if (strs[0][w] == '\0')
            return strs[0];

        for (i = 1; i < strsSize; i++)          // ???
        {
            if (strs[i][w] != strs[0][w])
            {
                strs[0][w] = '\0';
                return strs[0];
            }
        }
    }
}

/*
 int i, w = 1;
    while (strs[0][w] != '\0')
    {
        if (strs[0][w] == '\0')
            return strs[0];

        for (i = 1; i < strsSize; i++)
        {
            if (strs[i][w] != strs[0][w])
            {
                strs[0][w] = '\0';
                return strs[0];
            }
        }
        w++;
    }
    return strs[0];
*/

// ref: https://leetcode.com/problems/longest-common-prefix/solutions/1869031/c-0ms/?page=3&languageTags=c