// 33. Search in Rotated Sorted Array

// ref: https://youtu.be/U8XENwh8Oy8
// ref: https://leetcode.com/problems/search-in-rotated-sorted-array/solutions/427469/c-very-easy-to-understand-100-faster-binary-search-solution/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, m;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;

            // if left half is sorted and target is in left half then search in left half else search in right half
            else if (nums[m] >= nums[l])
            {
                if (target >= nums[l] && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            // if right half is sorted and target is in right half then search in right half else search in left half
            else
            {
                if (target <= nums[r] && target > nums[m])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return -1;
    }
};