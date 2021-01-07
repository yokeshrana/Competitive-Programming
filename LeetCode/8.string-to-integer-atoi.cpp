/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int myAtoi(string s)
    {
        int sign = 1, i = 0;
        int result = 0;
        while (i < s.length() && s[i] == ' ')
            i++;
        if (i < s.length() && (s[i] == '+' || s[i] == '-'))
            s[i++] == '+' ? sign = 1 : sign = -1;

        while (i < s.length() && s[i] >= '0' && s[i] <= '9')
        {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
                return sign == 1 ? INT_MAX : INT_MIN;
            result = result * 10 + (s[i++] - '0');
        }

        return result * sign;
    }
};
// @lc code=end
