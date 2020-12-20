/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */
#include <stdc++.h>
using namespace std;
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
    string preorder(TreeNode *s, bool isleft)
    {
        if (!s)
        {
            if (isleft)
                return "#lnull";
            else
                return "#rnull";
        }
        return "#" + to_string(s->val) + preorder(s->left, true) + preorder(s->right, false);
    }
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        string pre_s, pre_t;
        pre_s = preorder(s, true);
        pre_t = preorder(t, true);
        // cout<<pre_s<<endl<<pre_t;
        // pre_s.length()>=pre_t.length()?pre_s.find(pre_t)!=string::npos:pre_t.find(pre_s)!=string::npos; if asked anyone can be subtree of each
        return pre_s.find(pre_t) != string::npos;
    }
};
// @lc code=end
