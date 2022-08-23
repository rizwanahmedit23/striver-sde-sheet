class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low!=high){
            int mid = (low+high)/2;
            int right;
            bool isUnique = true;
            if(nums[mid]==nums[mid+1]){
                right=mid+1;
            }
            else if(nums[mid]==nums[mid-1]){
                right=mid;
            }
            else{
                return nums[mid];
            }
            if(right%2==0){
                high=right-2;
            }
            else{
                low=right+1;
            }
        }
        return nums[low];
    }
};
