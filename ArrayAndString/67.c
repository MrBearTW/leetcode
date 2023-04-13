// 67. Add Binary

char *addBinary(char *a, char *b)
{
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int sizeAns = (sizeA > sizeB ? sizeA : sizeB) + 1;

    char *ans = malloc(sizeAns + 1);

    int sum = 0;

    ans[sizeAns] = '\0';

    while (sizeA > 0 || sizeB > 0 || sum > 0)
    {
        sizeAns = sizeAns - 1;
        if (sizeA > 0)
        {
            sizeA = sizeA - 1;
            sum = sum + a[sizeA] - '0';
        }
        if (sizeB > 0)
        {
            sizeB = sizeB - 1;
            sum = sum + b[sizeB] - '0';
        }
        ans[sizeAns] = sum % 2 + '0';
        sum = sum / 2;  // 2 --> 10 , 1 --> 01
    }
    
    return ans + sizeAns;
}

/*

Input: a = "11", b = "1"
Output: "100"

Input: a = "1010", b = "1011"
Output: "10101"

*/

// ref: https://leetcode.com/problems/add-binary/solutions/2061593/c-beginner-friendly/?page=2&languageTags=c