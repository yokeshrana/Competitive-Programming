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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
           vector<vector<int>> result;
        if(!root)
            return result;
        q.push(root);
     
        while(!q.empty()){
            int l=q.size();
            vector<int> sub;
            for(int i=0;i<l;i++){
                TreeNode *ele=q.front();
                q.pop();
                sub.push_back(ele->val);
                if(ele->left)
                    q.push(ele->left);
                if(ele->right)
                    q.push(ele->right);
            }
            result.push_back(sub);
        }
        return result;
    }
};