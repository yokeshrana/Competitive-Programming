/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 */

// @lc code=start
class Solution
{
public:
    int modexp(int a, int n, int mod)
    {
        a = a % mod;
        int res = 1;
        while (n > 0)
        {
            if (n & 1 == 1)
            {
                res = ((res % mod) * (a % mod)) % mod;
            }
            a = (a % mod) * (a % mod);
            n = n >> 1;
        }
        return res;
    }
    int superPow(int a, vector<int> &b)
    {
        int result = 1;
        int base = a;
        for (int i = b.size() - 1; i >= 0; i--)
        {
            result = (result % 1337) * (modexp(base, b[i], 1337) % 1337);
            base = modexp(base, 10, 1337) % 1337;
        }
        return result % 1337;
    }
};
// @lc code=end
