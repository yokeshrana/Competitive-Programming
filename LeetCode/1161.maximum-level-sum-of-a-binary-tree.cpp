/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int level = 1;
        int maxsum = INT_MIN;
        int minlevel = 1;
        while (!q.empty())
        {
            int l = q.size();
            int sum = 0;
            for (int i = 0; i < l; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                sum += curr->val;
            }
            if (maxsum < sum)
            {
                maxsum = sum;
                minlevel = level;
            }
            level++;
        }
        return minlevel;
    }
};
// @lc code=end
