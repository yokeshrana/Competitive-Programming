/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rs = 0, cs = 0, re = matrix.size() - 1, ce = matrix[0].size() - 1, i;
        vector<int> v;
        while (rs <= re && cs <= ce)
        {

            for (i = cs; i <= ce; i++)
                v.push_back(matrix[rs][i]);
            for (i = rs + 1; i <= re; i++)
                v.push_back(matrix[i][ce]);
            if (rs < re && cs < ce)
            {
                for (i = ce - 1; i > cs; i--)
                    v.push_back(matrix[re][i]);
                for (i = re; i > rs; i--)
                    v.push_back(matrix[i][cs]);
            }
            rs++;
            re--;
            cs++;
            ce--;
        }
        return v;
    }
};
// @lc code=end
