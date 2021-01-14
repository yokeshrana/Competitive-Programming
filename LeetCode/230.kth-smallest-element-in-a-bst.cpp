/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    //Other Solution can be level order traversal and break in b/w when count becomes equal to k
    void inorder(TreeNode *root, vector<int> &v)
    {

        if (root)
        {

            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> v;
        inorder(root, v);
        return v[k - 1];
    }
};
// @lc code=end
