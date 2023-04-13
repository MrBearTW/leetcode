// 209. Minimum Size Subarray Sum

int minSubArrayLen(int target, int *nums, int numsSize)
{

    int sum = 0;
    int min = INT_MAX;      // ???
    for (int i = 0, j = 0; j < numsSize && i < numsSize;)
    {
        if (sum + nums[j] >= target)
        {
            if ((j - i + 1) < min)
            {
                min = (j - i + 1);
            }
            sum -= nums[i];
            i++;
        }
        else
        {
            sum += nums[j];
            j++;
        }
    }
    return (min == INT_MAX) ? 0 : min;
}



//  Time Limit Exceeded
/*
int minSubArrayLen(int target, int *nums, int numsSize)
{
    int i, s, w, sum = 0;
    for (i = 1; i <= numsSize; i++) // sum number
    {
        for (s = 0; (i + s) <= numsSize; s++) // start ponint
        {
            for (w = s; w < (i + s); w++) // Sum i from s
            {
                sum += nums[w];
            }
            if (sum >= target)
            {
                return i;
            }
            sum = 0;
        }
    }
    return 0;
}
*/

// ref: https://leetcode.com/problems/minimum-size-subarray-sum/solutions/2295749/c-sliding-window/?page=10&languageTags=c