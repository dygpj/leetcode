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
 void inod(TreeNode* root, vector<int> &res){
        if (root!=NULL){
            inod(root->left,res);
            res.push_back(root->val);
            inod(root->right,res);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inod(root,res);
        return res;
    }
};
