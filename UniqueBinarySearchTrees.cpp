class Solution {
public:
    int numTrees(int n) {
        if (n==0) return 1;
        if (n==1) return 1;
        vector<int> nTree;
        nTree.push_back(numTrees(0));
        nTree.push_back(numTrees(1));
        for(int i=2;i<n+1;i++){
            int tmp;
            tmp=0;
            for(int j=0;j<i;j++){
                tmp+=nTree[j]*nTree[i-1-j];
        }
        nTree.push_back(tmp);
    }
    return nTree[n];
    }
};
