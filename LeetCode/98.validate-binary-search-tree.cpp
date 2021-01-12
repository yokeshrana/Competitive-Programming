/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode *root)
    {
        long long int temp = LONG_MIN;
        stack<TreeNode *> st;
        while (1)
        {
            while (root)
            {
                st.push(root);
                root = root->left;
            }
            if (st.empty())
                break;
            root = st.top();
            cout << root->val << " ";
            if (root->val > temp)
                temp = root->val;
            else
                return false;
            st.pop();
            root = root->right;
        }
        return true;
    }
};
// @lc code=end
