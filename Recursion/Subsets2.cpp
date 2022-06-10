/*ex:1 
Input: [1,2,2]
Correct Output: [[], [1], [2], [1,2]]
Explanation: [2,2] is not a set because set cannot have duplicate elements. 
If they are considered as different elements then why is the subset [1,2] present only once. 2 at index 1 and index 2 must form two subsets with one.
*/
class Solution {
void subsets(vector<int>& nums, vector<vector<int>>& output, int index, vector<int>& subset, int n, bool prev = false){
        
        if(index == n){
            output.push_back(subset);
            return;
        }
        //  Ignore element
        subsets(nums, output, index+1, subset, n, false);
        if(index>0 && nums[index-1] == nums[index] && !prev){
            return;
        }
        // Take element
        
        subset.push_back(nums[index]);
        subsets(nums, output, index+1, subset, n, true);
        
        subset.pop_back();
    
        
        return;
        
    } 
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        vector<int> subset;
        int n = nums.size();
        subsets(nums, output,0, subset, n);
        return output;
    }
};
