// 487. Max Consecutive Ones II

// "Given a binary array, find the maximum number of consecutive 1s in this array, allowing at most one 0 within an otherwise consecutive run of 1s"
// 開頭是零 中間一個零 收尾一個零


// Approach 1: Brute Force
/*
int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int l, zeroes, r, longest = 0;
    for (l = 0; l < numsSize; l++)
    {
        zeroes = 0;

        for (r = l; r < numsSize; r++)
        {
            if (nums[r] == 0)
            {
                zeroes++;
            }
            if (zeroes <= 1)
            {
                if (r - l + 1 > longest)
                {
                    longest = r - l + 1;
                }
            }
        }
    }
    return longest;
}
// Time Limit Exceeded

*/


// Approach 2: Sliding Window
// R 先動，L 再動，只能包含一個零
int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int l = 0, zeroes = 0, r = 0, longest = 0;
    while (r < numsSize)
    {
        if (nums[r] == 0)
        {
            zeroes++;
        }

        while (zeroes == 2)
        {
            if (nums[l] == 0)
            {
                zeroes--;
            }
            l++;
        }
        if (r - l + 1 > longest)
        {
            longest = r - l + 1;
        }
        r++;
    }
    return longest;
}

// https://leetcode.com/problems/max-consecutive-ones-ii/editorial/