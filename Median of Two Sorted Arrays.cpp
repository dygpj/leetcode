#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if ((m+n)%2==1) return findk(nums1,nums2,0,m-1,0,n-1,(m+n+1)/2);
        if ((m+n)%2==0) return (findk(nums1,nums2,0,m-1,0,n-1,(m+n)/2)+findk(nums1,nums2,0,m-1,0,n-1,(m+n)/2+1))/2;
    }

    double findk(vector<int>& nums1, vector<int>& nums2,int begin1,int end1,int begin2,int end2,int k){//find kth element begin1-end1 and begin2-end2
           if (end1<begin1) return nums2[begin2+k-1];
           if (end2<begin2) return nums1[begin1+k-1];
           int mid1,mid2;
           mid1=int((end1+begin1)/2);
           mid2=int((end2+begin2)/2);
           if (nums1[mid1]==nums2[mid2]){
               int cntmp=mid1-begin1+mid2-begin2;
            if (cntmp==k-1 || cntmp==k-2) return nums1[mid1];
            else if (cntmp>k-1) return findk(nums1,nums2,begin1,mid1-1,begin2,mid2-1,k);
            else return findk(nums1,nums2,mid1+1,end1,mid2+1,end2,k-(cntmp+2));
           }
            else if (nums1[mid1]>nums2[mid2]){
                int cntmp1=mid2-begin2;
                int cntmp2=mid1-begin1;
                if (k<cntmp1+1) return findk(nums1,nums2,begin1,mid1-1,begin2,mid2-1,k);
                if (k<cntmp1+cntmp2+2) return findk(nums1,nums2,begin1,mid1-1,begin2,end2,k);
                return findk(nums1,nums2,begin1,end1,mid2+1,end2,k-(cntmp1+1));
            }
            else {
                int cntmp1=mid1-begin1;
                int cntmp2=mid2-begin2;
                if (k<cntmp1+1) return findk(nums1,nums2,begin1,mid1-1,begin2,mid2-1,k);
                if (k<cntmp1+cntmp2+2) return findk(nums1,nums2,begin1,end1,begin2,mid2-1,k);
                return findk(nums1,nums2,mid1+1,end1,begin2,end2,k-(cntmp1+1));
            }
    }
};

int main() {
        vector<int> nums1,nums2;
        nums1.push_back(1);nums1.push_back(2);
        nums2.push_back(3);nums2.push_back(4);nums2.push_back(5);
        Solution s;
        cout<<s.findMedianSortedArrays(nums1,nums2);
        return 0;
}
