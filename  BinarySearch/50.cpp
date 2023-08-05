// 50. Pow(x, n)

// ref: https://youtu.be/g9YQyYi4IQQ
// ref: https://leetcode.com/problems/powx-n/solutions/739646/c-iterative-vs-recursive-bitwise-solutions-explained-100-time-80-space/

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1;
        while (n)
        {
            if (n % 2)
            {
                if (n > 0)
                {
                    ans = ans * x;
                }
                else
                {
                    ans = ans / x;
                }
            }
            x = x * x;
            n = n / 2;
        }
        return ans;
    }
};