/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        int k = 0, tmp, j;
        for (int i = 1; i < A.size(); i++)
        {
            tmp = A[i];
            j = i;
            if (tmp % 2 == 0)
            {
                while (j > k)
                    A[j--] = A[j - 1];
                A[k++] = tmp;
            }
        }
        return A;
    }
};
// @lc code=end

//TODO :: Try Quick Sort Based Approach