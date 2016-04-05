class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()==0) return;
        int i=nums.size()-1;
        int j;
        int tmp;
        while(i>0 && nums[i]<=nums[i-1]){i--;}
        if(i!=0){
            j=nums.size()-1;
            while(nums[j]<=nums[i-1]) j--;
            tmp=nums[i-1];
            nums[i-1]=nums[j];
            nums[j]=tmp;
        }
        //if i=0
        j=nums.size()-1;
        while(i<j){
            tmp=nums[i];
            nums[i]=nums[j];
            nums[j]=tmp;
            i++;j--;
        }
    }
};