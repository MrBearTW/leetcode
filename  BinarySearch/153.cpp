// 153. Find Minimum in Rotated Sorted Array

// ref: https://youtu.be/nIVW4P8b1VA
// ref: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solutions/3176170/solution/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l < r)
        {
            // array is sorted in ascending order if first element is less than last element then return first element as minimum element in array
            if (nums[l] <= nums[r])
            {
                return nums[l];
            }
            
            // Prevent (l + r) overflow
            int mid = l + (r - l) / 2;
            
            // if l is greater than mid then minimum is in left half then r = mid
            if (nums[l] > nums[mid])
            {
                r = mid;
            }
            // else if mid is greater than r then minimum is in right half then l = mid + 1
            else if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
        }
        // array is sorted in ascending order if first element is less than last element then return first element as minimum element in array
        if (nums[l] <= nums[r])
        {
            return nums[l];
        }
        return -1;
    }
};