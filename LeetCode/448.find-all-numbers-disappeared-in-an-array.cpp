/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    //Note the arra contain elements from 1 to nums.size()
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {

        for (int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            temp = temp > 0 ? temp : -temp;
            if (nums[temp - 1] > 0)
                nums[temp - 1] *= -1;
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                res.push_back(i + 1);
        }
        return res;
    }
};

/* Mark Off values that are already visited by negating them
Finally in the next pass see the indexes at which values are positice ,these indices are our answers*/
// @lc code=end