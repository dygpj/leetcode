class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        bool flag1[len],flag2[len];
        for (int i=0;i<len;i++) {flag1[i]=1;flag2[i]=1;}
        int maxsize=1;
        int start=0;
        int end=0;
        bool isend1=1,isend2=1;
        for (int j=1;j<len;j++){
            bool istmp=0;
            for (int i=0;i<len-j;i++){
            if (flag1[i+1]==1 && s[i]==s[i+j]) flag1[i]=1;
            else flag1[i]=0;
            if (flag1[i]==1 && j+1>maxsize)
            {
                maxsize=j+1;
                start=i;
                end=i+j;
                istmp=1;
            }
            bool tmp=flag2[i];
            flag2[i]=flag1[i];
            flag1[i]=tmp;
            }
            flag1[len-j]=flag1[len-j];
            isend1=isend2;
            isend2=istmp;
            if (isend1==0 && isend2==0) break;
        }
        return s.substr(start,maxsize);
    }
};
