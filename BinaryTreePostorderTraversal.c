/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void postod(TreeNode* root, vector<int> &res){
        if (root!=NULL){
            postod(root->left,res);
            postod(root->right,res);
            res.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postod(root,res);
        return res;
    }
};
