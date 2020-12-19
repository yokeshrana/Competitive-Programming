/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */
using namespace std;
#include <stdc++.h>
// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string S, string T)
{
    int s_len = S.length(), t_len = T.length();
    int m = 0, n = 0;
    bool is_equal = true;
    int i_dx = 0;
    for (int i = 0; i < s_len; i++)
        if (S[i] == '#')
        {
            m--;
            m = max(0, m);
        }
        else
        {
            S[m++] = S[i];
        }

    for (int i = 0; i < t_len; i++)
        if (T[i] == '#')
        {
            n--;
            n = max(0, n);
        }
        else
        {
            T[n++] = T[i];
        }

    if (m != n)
        return false;

    for (int i = 0; i < m; i++)
        if (S[i] != T[i])
            return false;

    return true;
}
};
// @lc code=end
