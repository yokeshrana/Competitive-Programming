/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int l = arr.size(), j;
        for (int i = 0; i < l - 1; i++)
        {
            if (arr[i] == 0)
            {
                {

                    j = l - 1;
                    while (j != i + 1)
                        arr[j--] = arr[j - 1];
                    arr[i + 1] = 0;
                    i++;
                }
            }
        }
        return;
    }
};
// @lc code=end
