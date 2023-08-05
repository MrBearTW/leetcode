// 167. Two Sum II - Input Array Is Sorted

// ref: https://youtu.be/cQ1Oz4ckceM

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;  // initialize two pointers l and r to first and last index of array

        while (l < r)
        {
            if (numbers[l] + numbers[r] == target)    // if sum of elements at l and r is equal to target then return l + 1 and r + 1 as answer
            {
                return {l + 1, r + 1};
            }
            else if (numbers[l] + numbers[r] < target)   // if sum of elements at l and r is less than target then increment l by 1 to increase sum of elements
            {
                l++;
            }
            else    // if sum of elements at l and r is greater than target then decrement r by 1 to decrease sum of elements
            {
                r--;
            }
        }
        return {-1, -1};
    }
};