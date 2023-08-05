// 349. Intersection of Two Arrays

// ref: 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            vector<int> ans;
            int n1 = nums1.size();
            int n2 = nums2.size();
            int i = 0, j = 0;

            // sort both arrays to apply two pointer approach to find intersection of two arrays in O(nlogn) time complexity and O(1) space complexity
            sort(nums1.begin(), nums1.end()); 
            sort(nums2.begin(), nums2.end());

            // iterate over both arrays and check if both elements are equal then push that element in ans vector and increment both pointers 
            while (i < n1 && j < n2)
            {
                if (nums1[i] == nums2[j])
                {
                    if (ans.size() == 0 || ans[ans.size() - 1] != nums1[i]) // check if ans vector is empty or last element of ans vector is not equal to current element then push that element in ans vector
                    {
                        ans.push_back(nums1[i]); // push element in ans vector
                    }
                    i++;
                    j++;
                }
                else if (nums1[i] < nums2[j])   // else increment pointer of smaller element to move forward in that array to find intersection of two arrays
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
            return ans;
    }
};