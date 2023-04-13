// 151. Reverse Words in a String
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverseWords(char *s)
{
    int i = 0;  // single word long
    int j = 0;
    int a = strlen(s);
    char *res = malloc(a + 1);
    a--;
    int len = a;
    while (len >= 0)
    {
        // handle ' ' // trim to just one ' '?
        while (len >= 0 && s[len] == ' ')
        {
            len--;
        }

        // Count
        while (len >= 0 && s[len] != ' ' && ++i)
        {
            len--;
        }
        a = len + 1;    // a is single word start position

        // Reverse word
        while (--i >= 0)
        {
            res[j++] = s[a++];
        }

        // Set ' ' between words
        res[j++] = ' ';

        i = 0;
    }

    if (res[j - 2] == ' ')
    {
        res[j - 2] = '\0';
    }

    res[j - 1] = '\0';

    return (res);
}

int main(void)
{
    char s[] = {"    hello world    "};
    //reverseWords(s);

    puts(reverseWords(s));
    return 0;
}


// ref: https://leetcode.com/problems/reverse-words-in-a-string/solutions/1948896/simple-c-solution/?page=3&languageTags=c