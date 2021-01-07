/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int sign = 1;
        x > 0 ? sign = 1 : sign = -1;
        int result = 0;
        if (sign == -1)
        {
            if (x == INT_MIN)
                return 0;
            x = x * -1;
        }
        while (x)
        {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && x % 10 > INT_MAX / 10))
                return 0;
            result = result * 10 + x % 10;
            x = x / 10;
        }
        return result * sign;
    }
};
// @lc code=end
