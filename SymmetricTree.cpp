class Solution {
public:
    bool ismir(TreeNode* root1,TreeNode* root2){
        if ((root1==NULL) != (root2==NULL)) return false;
        if ((root1==NULL) && (root2==NULL)) return true;
        return (root1->val==root2->val) && ismir(root1->left,root2->right) && ismir(root2->left,root1->right);
    }

    bool isSymmetric(TreeNode* root) {
        return ismir(root,root);
    }
};
