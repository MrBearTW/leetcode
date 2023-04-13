// 557. Reverse Words in a String III

char *reverseWords(char *s)
{
    int lastSpaceIndex = -1, startIndex, endIndex;
    int len = strlen(s);
    char temp;
    for (int strIndex = 0; strIndex <= len; strIndex++)
    {
        if (strIndex == len || s[strIndex] == ' ')
        {
            startIndex = lastSpaceIndex + 1; // start position
            endIndex = strIndex - 1;         // end position
            while (startIndex < endIndex)    // do switch
            {
                temp = s[startIndex];
                s[startIndex] = s[endIndex];
                s[endIndex] = temp;
                startIndex++;
                endIndex--;
            }
            lastSpaceIndex = strIndex; // next start
        }
    }
    return s;
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *reverseWords(char *s)
{
    int i = 0, wr = 0, st = 0, wl = 0;
    int length = strlen(s);
    char *ans = malloc(length + 1);

    while (i < length)
    {
        while (i < length && s[i] != ' ')
        {
            wl++;
            i++;
        }
        while (wl > 0)
        {
            wl--;
            ans[wr] = s[st + wl];
            wr++;
        }
        while (i < length && s[i] == ' ')
        {
            i++;
            ans[wr] = ' ';
            wr++;
        }
        st = i;
        wl = 0;
    }
    return ans;
}

int main(void)
{
    char s[] = {"Let's take LeetCode contest"};
    printf("%s", reverseWords(s));

    return 0;
}

*/