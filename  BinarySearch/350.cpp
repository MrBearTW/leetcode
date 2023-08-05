// 350. Intersection of Two Arrays II

// ref: https://leetcode.com/problems/intersection-of-two-arrays-ii/solutions/3438183/beats-100-0ms-c-solution/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        // sort both arrays to apply two pointer approach to find intersection of two arrays in O(nlogn) time complexity and O(1) space complexity
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        int i = 0, j = 0;
        // iterate over both arrays and check if both elements are equal then push that element in ans vector and increment both pointers
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return res;
    }
};