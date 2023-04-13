// 167. Two Sum II - Input Array Is Sorted

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *ans = malloc(sizeof(int) * (*returnSize));
    //int ans[*returnSize] = {0};
    int low = 0, hight = numbersSize - 1, sum = 0;
    while (low < hight)
    {
        sum = numbers[low] + numbers[hight];
        if (sum == target)
        {
            ans[0] = low + 1;
            ans[1] = hight + 1;
            return ans;
        }
        else if (sum > target)
        {
            hight--;
        }
        else
        {
            low++;
        }
    }
    return ans;
}


// ref: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/solutions/2876563/c-simple-solution/?languageTags=c