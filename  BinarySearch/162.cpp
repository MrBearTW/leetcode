// 162. Find Peak Element

// ref: https://youtu.be/kMzJy9es7Hc

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, m;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (m > 0 && nums[m] < nums[m - 1])
                r = m - 1;
            else if (m < nums.size() - 1 && nums[m] < nums[m + 1])
                l = m + 1;
            else
                return m;
        }
        return -1;
    }
};