/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int l = 0;
        if (arr.size() == 1)
            return false;
        if (arr[1] <= arr[0])
            return false;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (l % 2 == 0 && arr[i + 1] <= arr[i])
                l++;
            if (l % 2 == 1 && arr[i + 1] >= arr[i])
                l++;
            if (l > 1)
                return false;
        }
        if (l == 0)
            return false;
        else
        {
            return true;
        }
    }
};
// @lc code=end
//More better Approarch is
//https://leetcode.com/problems/valid-mountain-array/solution/