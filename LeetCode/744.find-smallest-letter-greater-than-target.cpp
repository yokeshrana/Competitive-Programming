/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
         auto it=std::upper_bound(letters.begin(),letters.end(),target);
        if(it==letters.end()){
            return *(letters.begin());
        }
        else
            return *(it++);
    }
};
// @lc code=end

