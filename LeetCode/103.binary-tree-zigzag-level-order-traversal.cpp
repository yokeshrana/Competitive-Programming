/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> result;
        vector<int> res;
        if (!root)
            return {};
        q.push(root);
        bool flag = 0;
        while (!q.empty())
        {
            int l = q.size();
            for (int i = 0; i < l; i++)
            {
                TreeNode *curr = q.front();
                res.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                q.pop();
            }
            if (res.size() > 0)
            {
                if (flag == 1)
                    reverse(res.begin(), res.end());
                result.push_back(res);
                res.clear();
                if (flag)
                    flag = 0;
                else
                    flag = 1;
            }
        }
        return result;
    }
};
// @lc code=end
