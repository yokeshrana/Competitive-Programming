/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
#include "stdc++.h"
using namespace std;
// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        //boyee Moore Algorithm
        int m_element = nums[0];
        int count = 0;
        for (auto a : nums)
        {
            if (m_element == a)
            {
                count++;
            }
            else
            {
                count--;
                if (count == 0){
                    m_element = a;
                    count++;
                }
            }
        }
        /*
        //verify if m_element is majority or not
        int v_count = 0;
        for (auto a : nums)
            if (a == m_element)
                v_count++;
        if (v_count > nums.size() / 2)
            return m_element;
        else
        {
            return -1;
        }
        */
       return m_element;
    }
};
// @lc code=end
