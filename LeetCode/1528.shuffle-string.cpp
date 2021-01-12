/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 */

// @lc code=start
class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        string result = s;
        for (int i = 0; i < s.length(); i++)
            result[indices[i]] = s[i];
        return result;
    }
};
// @lc code=end
