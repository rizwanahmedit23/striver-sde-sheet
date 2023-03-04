class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int small = prices[0];
        int maxprofit = 0;
        
        for(int i=1;i<prices.size();i++){
            int curr = prices[i];
            if(curr < small){
                small = curr;
            }
            else if(curr > small){
                int currSum = curr - small;
                maxprofit = max(maxprofit, currSum);
            }
        }
        
        return maxprofit;
    }
};
