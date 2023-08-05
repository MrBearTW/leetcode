// 658. Find K Closest Elements

// ref: https://youtu.be/o-YDQzHoaKM
// rtf: https://leetcode.com/problems/find-k-closest-elements/solutions/106426/java-c-python-binary-search-o-log-n-k-k/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;   // right = arr.size() - k because we want to make sure that the last element is included in the result
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;

            if (x - arr[mid] > arr[mid + k] - x)    // x is closer to arr[mid + k]
            {
                left = mid + 1;
            }
            else    // x is closer to arr[mid]
            {
                right = mid;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};