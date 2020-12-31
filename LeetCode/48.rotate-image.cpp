/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    // transpose and reverse each rows
    for(int i=0;i<matrix.size();i++)
        for(int j=i;j<matrix[0].size();j++)
            if(i!=j)
            swap(matrix[i][j],matrix[j][i]);
     for(int i=0;i<matrix.size();i++)
         reverse(matrix[i].begin(),matrix[i].end());
    
    }
};
// @lc code=end

