// 410. Split Array Largest Sum

// ref: https://youtu.be/YUF3_eBdzsk

#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 0;
        for(int i = 0; i < nums.size(); i++) {
            l = max(l, nums[i]);
            r += nums[i];
        }

        while(l < r) {
            int mid = l + (r - l) / 2;
            int sum = 0, cnt = 1;
            for(int i = 0; i < nums.size(); i++) {
                if(sum + nums[i] > mid) {
                    cnt++;
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            }

            if(cnt > k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
        
    }
};