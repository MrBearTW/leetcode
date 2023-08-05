// 154. Find Minimum in Rotated Sorted Array II

// ref: https://youtu.be/K0PjrikGKK4

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])    // if mid is greater than r then minimum is in right half then l = mid + 1
            {
                l = mid + 1;
            }
            else if (nums[mid] < nums[r])   // if r is greater than mid then minimum is in left half then r = mid
            {
                r = mid;
            }
            else    // if mid is equal to r then decrement r by 1 and check again for minimum element in array
            {
                r--;    
            }
        }
        return nums[l];
    }
};