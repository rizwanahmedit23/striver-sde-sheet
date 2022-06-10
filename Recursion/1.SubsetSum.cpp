    void subsets(vector<int>& nums, vector<int>& output, int index, vector<int>& subset, int n, int sum){
        
        if(index == n){
            output.push_back(sum);
            return;
        }
         
        // subset.push_back(nums[index]);
        subsets(nums, output, index+1, subset, n, sum+nums[index]);
        
        subset.pop_back();
        subsets(nums, output, index+1, subset, n, sum);
        return;
        
    } 

    vector<int> subsetSums(vector<int> nums, int N)
    {
        // Write Your Code here
        vector<int> output;
        vector<int> subset;
        int n = nums.size();
        subsets(nums, output,0, subset, n, 0);
        return output;
        
    }
