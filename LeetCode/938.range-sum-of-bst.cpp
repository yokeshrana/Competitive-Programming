/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int sum = 0;
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root)
        {
            int l = rangeSumBST(root->left, low, high);
            int r = rangeSumBST(root->right, low, high);
            if (root->val >= low && root->val <= high)
                sum += root->val;
        }
        else
            return 0;
        return sum;
    }
};
// @lc code=end
