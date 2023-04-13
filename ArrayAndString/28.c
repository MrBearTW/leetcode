// 28. Find the Index of the First Occurrence in a String

int strStr(char *haystack, char *needle)
{
    int windowStart, windowIndex;
    int n = strlen(needle);
    int h = strlen(haystack);

    for (windowStart = 0; windowStart <= h - n; windowStart++)
    {
        for (windowIndex = 0; windowIndex < n; windowIndex++)
        {
            if (haystack[windowStart + windowIndex] != needle[windowIndex])
            {
                break;
            }
            if (windowIndex + 1 == n)
            {
                return windowStart;
            }
        }
    }
    return -1;
}

// ref: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/editorial/