// 287. Find the Duplicate Number

// ref: https://youtu.be/wjYnzkAhcNk

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0], ans = nums[0];
        
        // find the intersection point of the two runners (slow and fast)
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // find the entrance of the cycle (duplicate number)
        while(slow != ans) {
            slow = nums[slow];
            ans = nums[ans];
        }

        return ans;
    }
};