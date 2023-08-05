// 278. First Bad Version

// ref: https://leetcode.com/problems/first-bad-version/solutions/2724423/3-lines-binary-search-java-c/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 0;
        int right = n;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid) == 1)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
