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
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int l=q.size();
            double sum=0;
            for(int i=0;i<l;i++){
                TreeNode *e = q.front();
                q.pop();
                sum+=e->val;
                if(e->left) q.push(e->left);
                if(e->right) q.push(e->right);
            }
            res.push_back(sum/(l*1.00));
        }
        return res;
    }
};