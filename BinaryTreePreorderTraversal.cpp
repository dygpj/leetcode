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
    void preod(TreeNode* root, vector<int> &res){
        if (root!=NULL){
            res.push_back(root->val);
            preod(root->left,res);
            preod(root->right,res);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preod(root,res);
        return res;

    }
};
