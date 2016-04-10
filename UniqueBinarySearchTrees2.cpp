/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //The code may be simplified.
class Solution {
public:
    vector<TreeNode*> genTree(int n,int start){  //be clear to {} function domain of element
        vector<TreeNode*> gTreeVec;
        for (int i=0;i<n;i++){
            vector<TreeNode*> gTreeVecL;
            vector<TreeNode*> gTreeVecR;
            if (i==1) {TreeNode* TrL=new TreeNode(start);gTreeVecL.push_back(TrL);}
            else if (i!=0) {
                gTreeVecL=genTree(i,start);
            }
            if (n-i-1==1) {TreeNode* TrR=new TreeNode(start+i+1);gTreeVecR.push_back(TrR);}
            else if (n-i-1!=0) {
                gTreeVecR=genTree(n-i-1,start+i+1);
            }
            if (gTreeVecL.size()==0 && gTreeVecR.size()==0){
                TreeNode* TrNode=new TreeNode(start+i);
                gTreeVec.push_back(TrNode);
            }
            else if (gTreeVecL.size()==0){
                for (int k=0;k<gTreeVecR.size();k++){
                TreeNode* TrNode=new TreeNode(start+i);
                TrNode->right=gTreeVecR[k];
                gTreeVec.push_back(TrNode);
                }
            }
            else if (gTreeVecR.size()==0){
                for (int j=0;j<gTreeVecL.size();j++){
                TreeNode* TrNode=new TreeNode(start+i);
                TrNode->left=gTreeVecL[j];
                gTreeVec.push_back(TrNode);
                }
            }
            else {
            for (int j=0;j<gTreeVecL.size();j++){
                for (int k=0;k<gTreeVecR.size();k++){
                TreeNode* TrNode=new TreeNode(start+i);
                TrNode->left=gTreeVecL[j];
                TrNode->right=gTreeVecR[k];
                gTreeVec.push_back(TrNode);
                }
            }
            }
        }
        return gTreeVec;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        res=genTree(n,1);
        return res;
    }
};
