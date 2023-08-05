// 34. Find First and Last Position of Element in Sorted Array

// ref: https://youtu.be/4sQL7R5ySUU

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        return {left, right};
    }

    int binarySearch(vector<int> &nums, int target, bool leftBias)
    {
        int left = 0, right = nums.size() - 1;
        int i = -1;

        while (left <= right)
        {
            // Prevent (left + right) overflow
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)    // found
            {
                i = mid;
                if (leftBias)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else if (nums[mid] < target)    // leftBias
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)    // rightBias
            {
                right = mid - 1;
            }    
        }
        return i;
    }
};