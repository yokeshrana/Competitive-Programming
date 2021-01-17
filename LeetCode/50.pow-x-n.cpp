/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        //computes all the powers in a loop, and multiplies the ones with the corresponding set bit in n
        long long i = n;
        double res = 1;
        if (i > 0)
        {
            while (i > 0)
            {
                if (i & 1)
                    res = res * x;
                x = x * x;
                i >>= 1;
            }
        }
        else
        {
            i = i * -1;
            while (i > 0)
            {
                if (i & 1)
                    res = res / x;
                x = x * x;
                i >>= 1;
            }
        }

        return res;
    }
};
// @lc code=end
