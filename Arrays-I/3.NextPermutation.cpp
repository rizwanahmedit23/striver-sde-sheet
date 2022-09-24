class Solution {
    void reverse(vector<int>& nums, int si){
        int i=si, j=nums.size()-1;
        while(i<=j){
            swap(nums[i], nums[j]);
            i++;j--;
        }
    }
public:
    void nextPermutation(vector<int>& nums) {
        int i, j;
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1])   break;
        }
        int idx1 = i;
        
        for(j=nums.size()-1; idx1!=-1 && j>idx1; j--){
            if(nums[j]>nums[i]) break;
        }
        int idx2 = j;
        if(idx1!=-1){
            swap(nums[idx1], nums[idx2]);
        }
        
        reverse(nums, idx1+1);
        return;
    }
};
